#pragma once

#include "Bamboo/Base.hpp"
#include "Bamboo/ScriptRegistry/TypeName.hpp"
#include "Bamboo/Allocator.hpp"
// #include "ScriptRegistry/ScriptRegistry.hpp"

#include <type_traits>
#include <string>

namespace Bamboo {

class Component;
class Script;

class Entity final {
public:
    Entity();
    Entity(EntityHandle handle);

    template<typename T>
        requires std::is_base_of_v<Component, T>
    T getComponent() {
        T component;
        component.m_entity = *this;
        return component;
    }

    /*
    template<typename T>
        requires std::is_base_of_v<Script, T>
    Shared<T> getScript() {
        auto entries = getScriptRegistry()->getEntityScripts(m_handle);
        for (auto [id, entry]: entries.instances) {
            if (SharedCast<T>(entry.script)) {
                return entry.script;
            }
        }
        return {};
    }
    */

    template<typename T>
        requires std::is_base_of_v<Component, T>
    void addComponent() {
        const std::string typeName = std::string(Bamboo::typeName<T>());
        createComponent(typeName);
    }

    bool isValid() {
        return m_handle.isValid();
    }

    EntityHandle getHandle() {
        return m_handle;
    }

    const char *getName();

private:
    void createComponent(const std::string &name);

    EntityHandle m_handle;

    friend class World;
};

} // namespace Bamboo