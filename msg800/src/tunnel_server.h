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

        using Buffer = std::array<uint8_t, 4096>;

        Buffer buffers[2];

        int half_shutdown;

        std::chrono::time_point<std::chrono::system_clock> last_active_time;

        Pair(boost::asio::io_context& context)
        : upstream(context),
          downstream(context),
          half_shutdown(0)
        {
        }
    };

    std::unique_ptr<NetworkProtocol> upstream_protocol_;
    std::unique_ptr<NetworkProtocol> downstream_protocol_;

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

    void transfer_write(socket&                                       r,
                        socket&                                       w,
                        NetworkProtocol*                              rp,
                        NetworkProtocol*                              wp,
                        Pair::Buffer&                                 buf,
                        const std::vector<boost::asio::const_buffer>& messages,
                        PairPtr                                       pair);

    void shutdown_pair(PairPtr pair);
    void shutdown_half_pair(PairPtr pair, socket& r, socket& w);

    void clear_zombie_pairs();
};

} // namespace yy::msg800
