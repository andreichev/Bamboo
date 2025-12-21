#pragma once

#include "Bamboo/Base.hpp"

namespace Bamboo {

namespace Rigidbody2DComponentAPI {
    void applyForce(EntityHandle entity, Vec2 force);
    void applyLinearImpulse(EntityHandle entity, Vec2 impulse);
    Vec2 getLinearVelocity(EntityHandle entity);
    void setLinearVelocity(EntityHandle entity, Vec2 velocity);
    float getMass(EntityHandle entity);
    float getFriction(EntityHandle entity);
    void setFriction(EntityHandle entity, float friction);
}; // namespace Rigidbody2DComponentAPI

} // namespace Bamboo