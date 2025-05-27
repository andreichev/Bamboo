#include "Bamboo/Logger.hpp"
#include "Panda/OuterScriptHook.hpp"

#include <string>

namespace Bamboo {

void Logger::log(MessageType type, std::string_view message) {
    std::string messageStr = {message.begin(), message.end()};
    Panda::ExternalCalls::console_Log(type, messageStr.c_str());
}

} // namespace Bamboo