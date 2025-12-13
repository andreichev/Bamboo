#pragma once

#include "Bamboo/Allocator.hpp"
#include "Bamboo/Entity.hpp"
#include "Bamboo/Script.hpp"

#include <string>
#include <unordered_map>
#include <vector>

namespace Bamboo {

using InstantiateScriptFunction = Bamboo::Shared<Bamboo::Script> (*)(Bamboo::Entity entity);
enum class ScriptFieldType { INTEGER, FLOAT, ENTITY, TEXTURE, MATERIAL, UNKNOWN };
using FieldHandle = uint32_t;
using Handle = uint32_t;

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

} // namespace Bamboo