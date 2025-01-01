#pragma once

#include <vector>
#include <Bamboo/Base.hpp>

namespace Panda {

using FieldHandle = uint32_t;

enum class ScriptFieldType { INTEGER, FLOAT, ENTITY, TEXTURE, UNKNOWN };

struct ScriptFieldManifest final {
    constexpr ScriptFieldManifest(FieldHandle handle, const char *name, ScriptFieldType type)
        : handle(handle)
        , name(name)
        , type(type) {}

    FieldHandle handle;
    const char *name;
    ScriptFieldType type;

    operator bool() const {
        return name;
    }
};

struct ScriptClassManifest final {
    const char *name = nullptr;
    std::vector<ScriptFieldManifest> fields;

    ScriptFieldManifest getField(const char *name) const {
        for (auto &field : fields) {
            if (Bamboo::strCmp(field.name, name) == 0) {
                return field;
            }
        }
        return {0, nullptr, ScriptFieldType::UNKNOWN};
    }

    operator bool() const {
        return name;
    }
};

struct ScriptBundleManifest final {
    std::vector<ScriptClassManifest> classes;

    ScriptClassManifest getClass(const char *name) const {
        for (auto &clazz : classes) {
            if (Bamboo::strCmp(clazz.name, name) == 0) {
                return clazz;
            }
        }
        return {};
    }
};

} // namespace Panda