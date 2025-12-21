#pragma once

#include "Base.hpp"

namespace Bamboo {

class Script {
public:
    virtual ~Script() = default;

    virtual void start() {};
    virtual void update(float deltaTime) {};
    virtual void beginCollisionTouch(EntityHandle other) {};
    virtual void endCollisionTouch(EntityHandle other) {};
    virtual void beginSensorOverlap(EntityHandle sensor) {};
    virtual void endSensorOverlap(EntityHandle sensor) {};
    virtual void shutdown() {};
    EntityHandle getEntity() {
        return m_entity;
    }

private:
    EntityHandle m_entity;

    friend class ScriptRegistry;
};

} // namespace Bamboo