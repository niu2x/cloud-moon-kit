#include <stdarg.h>

#include <yy/log.h>
#include <yy/rust_support.h>

namespace yy {

void init_logging()
{
    rust_init_logger();
}

struct LoggerInit {
    LoggerInit()
    {
        init_logging();
    }
};

void panic(const std::string& panic_msg)
{
    LOG(error) << panic_msg;
    throw std::runtime_error("blight panic: " + panic_msg);
}

void panic(const char* fmt, ...)
{
    static char msg_buf[1024];

    va_list ap;
    va_start(ap, fmt);
    vsnprintf(msg_buf, sizeof(msg_buf), fmt, ap);
    va_end(ap);

    panic(std::string(msg_buf));
}

Logger::Logger(LogLevel level)
: log_level_(level)
{
    static LoggerInit once_initer;
}

Logger::~Logger()
{
    write_log(buffer_.str().c_str());
}

void Logger::write_log(const char* message)
{
    if (log_level_ == LOG_LEVEL_trace) {
        rust_log_trace(message);
    } else if (log_level_ == LOG_LEVEL_debug) {
        rust_log_debug(message);
    } else if (log_level_ == LOG_LEVEL_info) {
        rust_log_info(message);
    } else if (log_level_ == LOG_LEVEL_warn) {
        rust_log_warn(message);
    } else if (log_level_ == LOG_LEVEL_error) {
        rust_log_error(message);
    }
}

} // namespace blight
