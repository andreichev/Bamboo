#include "Bamboo/Components/Rigidbody2DComponentAPI.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

namespace Rigidbody2DComponentAPI {
    void applyForce(EntityHandle entity, Vec2 force) {
        Panda::ExternalCalls::rigidbody2DComponent_ApplyForce(entity.id, force.x, force.y);
    }

    void applyLinearImpulse(EntityHandle entity, Vec2 impulse) {
        Panda::ExternalCalls::rigidbody2DComponent_ApplyLinearImpulse(
            entity.id, impulse.x, impulse.y
        );
    }

    Vec2 getLinearVelocity(EntityHandle entity) {
        Vec2 result;
        Panda::ExternalCalls::rigidbody2DComponent_GetLinearVelocity(
            entity.id, &result.x, &result.y
        );
        return result;
    }

    void setLinearVelocity(EntityHandle entity, Vec2 velocity) {
        Panda::ExternalCalls::rigidbody2DComponent_SetLinearVelocity(
            entity.id, velocity.x, velocity.y
        );
    }

    float getMass(EntityHandle entity) {
        float mass;
        Panda::ExternalCalls::rigidbody2DComponent_GetMass(entity.id, &mass);
        return mass;
    }

    float getFriction(EntityHandle entity) {
        float friction;
        Panda::ExternalCalls::rigidbody2DComponent_GetFriction(entity.id, &friction);
        return friction;
    }

    void setFriction(EntityHandle entity, float friction) {
        Panda::ExternalCalls::rigidbody2DComponent_SetFriction(entity.id, friction);
    }
} // namespace Rigidbody2DComponentAPI

} // namespace Bamboo
