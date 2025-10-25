#pragma once

#include <memory>
#include <chrono>
#include <set>

#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>

#include <yy/ip_addr.h>

#include "protocol.h"

namespace yy::msg800 {

class TunnelServer : private boost::noncopyable {
public:
    TunnelServer(boost::asio::io_context&         context,
                 const IP_Address&                local_addr,
                 const IP_Address&                remote_addr,
                 std::unique_ptr<NetworkProtocol> downstream_protocol,
                 std::unique_ptr<NetworkProtocol> upstream_protocol);
    ~TunnelServer();

    void startup();

private:
    boost::asio::io_context& io_context_;

    IP_Address local_addr_;
    IP_Address remote_addr_;

    using socket = boost::asio::ip::tcp::socket;

    std::unique_ptr<boost::asio::ip::tcp::acceptor> acceptor_;

    struct Pair {
        socket upstream;
        socket downstream;

        std::unique_ptr<NetworkProtocol> upstream_protocol;
        std::unique_ptr<NetworkProtocol> downstream_protocol;

        using Buffer = std::vector<uint8_t>;

        Buffer buffers[2];

        int half_shutdown;

        std::chrono::time_point<std::chrono::system_clock> last_active_time;

        Pair(boost::asio::io_context& context)
        : upstream(context),
          downstream(context),
          half_shutdown(0)
        {
            buffers[0].resize(16 * 2);
            buffers[1].resize(16 * 2);
        }
    };

    std::unique_ptr<NetworkProtocol> upstream_protocol_proto_;
    std::unique_ptr<NetworkProtocol> downstream_protocol_proto_;

    using PairPtr = std::shared_ptr<Pair>;

    std::set<PairPtr> alive_pairs_;

    void async_accept();
    void async_connect_remote(PairPtr pair);

    void bridge_pair(PairPtr pair);
    void bridge_half(socket&          r,
                     socket&          w,
                     NetworkProtocol* rp,
                     NetworkProtocol* wp,
                     Pair::Buffer&    buf,
                     PairPtr          pair);

    void transfer_some_data(socket&          r,
                            socket&          w,
                            NetworkProtocol* rp,
                            NetworkProtocol* wp,
                            Pair::Buffer&    buf,
                            PairPtr          pair);
    void transfer_read(socket&          r,
                       socket&          w,
                       NetworkProtocol* rp,
                       NetworkProtocol* wp,
                       Pair::Buffer&    buf,
                       PairPtr          pair);

    void transfer_write(socket&          r,
                        socket&          w,
                        NetworkProtocol* rp,
                        NetworkProtocol* wp,
                        Pair::Buffer&    buf,
                        size_t           bytes,
                        PairPtr          pair);

    void shutdown_pair(PairPtr pair);
    void shutdown_half_pair(PairPtr pair, socket& r, socket& w);

    void clear_zombie_pairs();
};

} // namespace yy::msg800
