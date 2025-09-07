#pragma once

#ifdef USE_STDFORMAT
#    include <format>
#endif
#include <string_view>

namespace Bamboo {

class Logger {
public:
    enum MessageType { INFO = 0, WARNING, ERROR };
    static void log(MessageType type, std::string_view message);

#ifdef USE_STDFORMAT
    template<typename... Args>
    static void log(MessageType type, std::format_string<Args...> fstr, Args &&...args) {
        std::string_view message = std::format(fstr, std::forward<Args>(args)...);
        log(type, message);
    }
#else
    template<typename... Args>
    static void log(MessageType type, const char *format, ...) {
        static const int32_t maxSize = 256;
        static char buffer[maxSize];
        va_list args;
        va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);
        std::string_view view = buffer;
        log(type, view);
    }
#endif
};

} // namespace Bamboo

#define LOG_INFO(...) Bamboo::Logger::log(Bamboo::Logger::MessageType::INFO, __VA_ARGS__)
#define LOG_WARN(...) Bamboo::Logger::log(Bamboo::Logger::MessageType::WARNING, __VA_ARGS__)
#define LOG_ERROR(...) Bamboo::Logger::log(Bamboo::Logger::MessageType::ERROR, __VA_ARGS__)