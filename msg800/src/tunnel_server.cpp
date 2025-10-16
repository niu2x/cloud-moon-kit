#include "tunnel_server.h"

#include <yy/charset.h>
#include <yy/log.h>

namespace yy::msg800 {

using namespace boost::asio::ip;
using boost::asio::ip::make_address_v4;
namespace asio = boost::asio;

TunnelServer::TunnelServer(asio::io_context& context,

                           const IP_Address& local_addr,
                           const IP_Address& remote_addr,

                           std::unique_ptr<NetworkProtocol> downstream_protocol,
                           std::unique_ptr<NetworkProtocol> upstream_protocol)
: io_context_(context),
  local_addr_(local_addr),
  remote_addr_(remote_addr)
{
    downstream_protocol_ = downstream_protocol ? std::move(downstream_protocol)
                                               : std::make_unique<NoneNetworkProtocol>();
                                               
    upstream_protocol_   = upstream_protocol ? std::move(upstream_protocol)
                                             : std::make_unique<NoneNetworkProtocol>();
}

TunnelServer::~TunnelServer()
{
}

void TunnelServer::startup()
{
    auto local_endpoint = tcp::endpoint(make_address_v4(local_addr_.ipv4), local_addr_.port);

    acceptor_ = std::make_unique<tcp::acceptor>(io_context_, local_endpoint);

    async_accept();
}

void TunnelServer::async_accept()
{
    auto pair = std::make_shared<Pair>(io_context_);

    acceptor_->async_accept(pair->downstream, [this, pair](auto err) {
        if (err) {
            LOG(error) << "accept error: " << charset::native_to_utf8(err.message());
        } else {
            LOG(info) << "accept a client";
            async_connect_remote(pair);
            async_accept();
        }
    });
}

void TunnelServer::async_connect_remote(PairPtr pair)
{
    auto remote_endpoint = tcp::endpoint(make_address_v4(remote_addr_.ipv4), remote_addr_.port);

    pair->upstream.async_connect(remote_endpoint, [this, pair](auto err) {
        if (err) {
            LOG(error) << "connect remote error: " << charset::native_to_utf8(err.message());
        } else {
            clear_zombie_pairs();

            pair->last_active_time = std::chrono::system_clock::now();
            alive_pairs_.insert(pair);
            bridge_pair(pair);

            LOG(info) << "open new pair";
            LOG(info) << "alive_pairs num: " << alive_pairs_.size();
        }
    });
}

void TunnelServer::bridge_pair(PairPtr pair)
{
    bridge_half(pair->upstream,
                pair->downstream,
                upstream_protocol_.get(),
                downstream_protocol_.get(),
                pair->buffers[0],
                pair);
    bridge_half(pair->downstream,
                pair->upstream,
                downstream_protocol_.get(),
                upstream_protocol_.get(),
                pair->buffers[1],
                pair);
}

void TunnelServer::bridge_half(socket&          r,
                               socket&          w,
                               NetworkProtocol* rp,
                               NetworkProtocol* wp,
                               Pair::Buffer&    buf,
                               PairPtr          pair)
{
    transfer_some_data(r, w, rp, wp, buf, pair);
}

void TunnelServer::transfer_some_data(socket&          r,
                                      socket&          w,
                                      NetworkProtocol* rp,
                                      NetworkProtocol* wp,
                                      Pair::Buffer&    buf,
                                      PairPtr          pair)
{
    transfer_read(r, w, rp, wp, buf, pair);
}

void TunnelServer::transfer_read(socket&          r,
                                 socket&          w,
                                 NetworkProtocol* rp,
                                 NetworkProtocol* wp,
                                 Pair::Buffer&    buf,
                                 PairPtr          pair)
{
    r.async_read_some(asio::buffer(buf), [&r, &w, rp, wp, &buf, pair, this](auto err, size_t n) {
        pair->last_active_time = std::chrono::system_clock::now();
        if (!err) {
            auto messages = rp->unpack(buf.data(), n);

            std::vector<std::vector<uint8_t>> pack_messages;
            for (auto& m : messages) {
                pack_messages.push_back(wp->pack(m.data(), m.size()));
            }

            std::vector<boost::asio::const_buffer> buffers;
            for (auto& m : pack_messages) {
                buffers.push_back(asio::buffer(m));
            }
            transfer_write(r, w, rp, wp, buf, buffers, pair);
        } else {
            if (err == boost::asio::error::eof) {
                LOG(info) << "half close pair";
                shutdown_half_pair(pair, r, w);
            } else {
                shutdown_pair(pair);
            }
        }
    });
}

void TunnelServer::transfer_write(socket&          r,
                                  socket&          w,
                                  NetworkProtocol* rp,
                                  NetworkProtocol* wp,
                                  Pair::Buffer&    buf,
                                  size_t           bytes,
                                  PairPtr          pair

)
{
    asio::async_write(w, asio::buffer(buf, bytes),
        [&r, &w, rp, wp, &buf, pair, this](auto err, size_t n) {
            pair->last_active_time = std::chrono::system_clock::now();
            if (err) {
                shutdown_pair(pair);
            } else {
                transfer_some_data(r, w, rp, wp, buf, pair);
            }
        });
}

void TunnelServer::transfer_write(socket&                                       r,
                                  socket&                                       w,
                                  NetworkProtocol*                              rp,
                                  NetworkProtocol*                              wp,
                                  Pair::Buffer&                                 buf,
                                  const std::vector<boost::asio::const_buffer>& messages,
                                  PairPtr                                       pair)
{

    asio::async_write(w, messages, [&r, &w, rp, wp, &buf, pair, this](auto err, size_t n) {
        if (err) {
            shutdown_pair(pair);
        } else {
            transfer_some_data(r, w, rp, wp, buf, pair);
        }
    });
}

void TunnelServer::shutdown_half_pair(PairPtr pair, socket& r, socket& w)
{
    boost::system::error_code ignore_err;
    w.shutdown(boost::asio::ip::tcp::socket::shutdown_send, ignore_err);
    r.shutdown(boost::asio::ip::tcp::socket::shutdown_receive, ignore_err);

    if (&r == &(pair->upstream))
        pair->half_shutdown++;

    if (&r == &(pair->downstream))
        pair->half_shutdown++;

    if (pair->half_shutdown == 2) {
        shutdown_pair(pair);
    }
}

void TunnelServer::shutdown_pair(PairPtr pair)
{
    auto it = alive_pairs_.find(pair);
    if (it != alive_pairs_.end()) {

        pair->upstream.close();
        pair->downstream.close();
        alive_pairs_.erase(it);

        LOG(info) << "close pair";
        LOG(info) << "alive_pairs num: " << alive_pairs_.size();
    }
}

void TunnelServer::clear_zombie_pairs() {
    auto now = std::chrono::system_clock::now();
    auto threshold = std::chrono::seconds(4);
    for(auto it = alive_pairs_.begin(); it != alive_pairs_.end(); ) {
        if(now - (*it)->last_active_time > threshold) {
            LOG(info) << "shutdown zombie pair";
            shutdown_pair(*(it ++) );
        }
        else {
            ++ it;
        }
    }
}

} // namespace yy::msg800