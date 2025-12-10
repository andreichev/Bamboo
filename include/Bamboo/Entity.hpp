#pragma once

#include "Bamboo/Base.hpp"

#include <type_traits>

namespace Bamboo {

class Component;

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

    bool isValid() {
        return m_handle.isValid();
    }

    EntityHandle getHandle() {
        return m_handle;
    }

    const char *getName();

private:
    EntityHandle m_handle;

    friend class World;
};

} // namespace Bamboo