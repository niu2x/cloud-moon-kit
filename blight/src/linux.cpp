#include <boost/process.hpp>
#include <boost/asio.hpp>

#include <yy/blight.h>

namespace yy::blight::linux {

void inject_so(pid_t pid, const std::string& dll_path)
{
    boost::asio::io_context ctx;

    boost::process::popen proc(ctx, "/usr/bin/gdb", {});

    std::stringstream ss;
    ss << "attach " << pid << "\n";
    ss << "call dlopen(\"" << dll_path << "\"," << 1 << ") " << "\n";
    ss << "detach" << "\n";
    ss << "quit" << "\n";

    boost::asio::write(proc, boost::asio::buffer(ss.str()));

    proc.wait();
}

} // namespace yy::blight::linux
