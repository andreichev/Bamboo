#pragma once

#include "Panda/Manifest/ScriptBundleManifest.hpp"
#include "Bamboo/Allocator.hpp"

#include <string>
#include <unordered_map>
#include <vector>

namespace Bamboo {
class Entity;
class Script;
} // namespace Bamboo

namespace Panda {

using InstantiateScriptFunction = Bamboo::Shared<Bamboo::Script> (*)(Bamboo::Entity entity);

struct ScriptFieldInfo final {
    constexpr ScriptFieldInfo(
        ScriptFieldType type, const char *name, uint32_t offset, uint32_t size, uint32_t align
    )
        : type(type)
        , name(name)
        , offset(offset)
        , size(size)
        , align(align) {}

    ScriptFieldType type;
    const char *name;
    uint32_t offset;
    uint32_t size;
    uint32_t align;
};

struct ScriptClass final {
    const char *name;
    InstantiateScriptFunction instantiateFunc;
    std::unordered_map<FieldHandle, ScriptFieldInfo> fields;
};

} // namespace Panda