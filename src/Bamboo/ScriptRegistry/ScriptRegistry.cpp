#include "Bamboo/ScriptRegistry/ScriptRegistry.hpp"

namespace Bamboo {

ScriptRegistry *getScriptRegistry() {
    static ScriptRegistry globalData;
    return &globalData;
}

} // namespace Bamboo