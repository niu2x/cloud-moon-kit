#pragma once

#include <sstream>

namespace yy {

class Logger {
public:
    enum LogLevel {
        LOG_LEVEL_off,
        LOG_LEVEL_error,
        LOG_LEVEL_warn,
        LOG_LEVEL_info,
        LOG_LEVEL_debug,
        LOG_LEVEL_trace,
    };

    explicit Logger(LogLevel level);
    ~Logger();

    template <class T>
    Logger& operator<<(const T& value)
    {
        buffer_ << value;
        return *this;
    }

    static void set_log_level_threshold(int level);

private:
    std::stringstream buffer_;
    LogLevel          log_level_;

    void write_log(const char* message);
};

void panic(const std::string& panic_msg);
void panic(const char* fmt, ...);

} // namespace yy

#define LOG(level) yy::Logger(yy::Logger::LOG_LEVEL_##level)

