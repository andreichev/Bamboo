#pragma once

#include "Bamboo/Base.hpp"
#include "Bamboo/Allocator.hpp"
#include "ScriptRegistry/ScriptRegistry.hpp"

#include <type_traits>
#include <string>

namespace Bamboo {

class Script;

enum class ComponentType {
    MESH_COMPONENT,
    RIGIDBODY_2D_COMPONENT,
    SPRITE_RENDERER_COMPONENT,
    TRANSFORM_COMPONENT
};

namespace EntityAPI {
    template<typename T>
        requires std::is_base_of_v<Script, T>
    Shared<T> getScript(EntityHandle handle) {
        auto entries = getScriptRegistry()->getEntityScripts(handle);
        for (auto [id, entry] : entries.instances) {
            Shared<T> script = SharedCast<T>(entry.script);
            if (script) {
                return script;
            }
        }
        return {};
    }

    void addComponent(EntityHandle handle, ComponentType type);

    const char *getName(EntityHandle handle);
}; // namespace EntityAPI

} // namespace Bamboo