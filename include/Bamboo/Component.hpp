#pragma once

#include "Entity.hpp"

namespace Bamboo {

class ScriptRegistry;

class Component {
public:
    Entity getEntity();

private:
    Entity m_entity;

    friend class Entity;
    friend class ScriptRegistry;
};

} // namespace Bamboo