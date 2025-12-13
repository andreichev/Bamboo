#pragma once

#include <string_view>
#include <unordered_map>

#include "ScriptRegistry/ScriptRegistry.hpp"

namespace Bamboo {

template<typename T>
struct AutoRegisterScriptClass {
    AutoRegisterScriptClass(const char *name) {
        getScriptRegistry()->registerScriptClass<T>(name);
    }
};

} // namespace Bamboo

// --------------------------------
// ---------- MACROS --------------
// --------------------------------

#define _PANDA_CONCAT_(a, b) a##b
#define _REGISTER_SCRIPT_INTERNAL(name, ID)                                                        \
    inline static Bamboo::AutoRegisterScriptClass<name> _PANDA_CONCAT_(registerScript_, ID)(#name);
#define REGISTER_SCRIPT(name) _REGISTER_SCRIPT_INTERNAL(name, __COUNTER__)

#define PANDA_FIELDS_BEGIN(classType)                                                              \
    static std::unordered_map<Bamboo::FieldHandle, Bamboo::ScriptFieldInfo> getFields() {          \
        using ClassType = classType;                                                               \
        int index = 1;                                                                             \
        std::unordered_map<Bamboo::FieldHandle, Bamboo::ScriptFieldInfo> fields;

#define PANDA_FIELD(name)                                                                          \
    fields.emplace(                                                                                \
        index++,                                                                                   \
        Bamboo::getScriptRegistry()->makeFieldInfo<decltype(name)>(                                \
            #name, Bamboo::offsetOf(&ClassType::name)                                              \
        )                                                                                          \
    );

#define PANDA_FIELDS_END                                                                           \
    return fields;                                                                                 \
    }