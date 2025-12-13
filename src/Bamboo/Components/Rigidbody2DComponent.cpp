#include "Bamboo/Components/Rigidbody2DComponent.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

void Rigidbody2DComponent::applyForce(Vec2 force) {
    EntityHandle entityHandle = getEntity().getHandle();
    Panda::ExternalCalls::rigidbody2DComponent_ApplyForce(entityHandle.id, force.x, force.y);
}

void Rigidbody2DComponent::applyLinearImpulse(Vec2 impulse) {
    EntityHandle entityHandle = getEntity().getHandle();
    Panda::ExternalCalls::rigidbody2DComponent_ApplyLinearImpulse(
        entityHandle.id, impulse.x, impulse.y
    );
}

Vec2 Rigidbody2DComponent::getLinearVelocity() {
    EntityHandle entityHandle = getEntity().getHandle();
    Vec2 result;
    Panda::ExternalCalls::rigidbody2DComponent_GetLinearVelocity(
        entityHandle.id, &result.x, &result.y
    );
    return result;
}

void Rigidbody2DComponent::setLinearVelocity(Vec2 velocity) {
    EntityHandle entityHandle = getEntity().getHandle();
    Panda::ExternalCalls::rigidbody2DComponent_SetLinearVelocity(
        entityHandle.id, velocity.x, velocity.y
    );
}

float Rigidbody2DComponent::getMass() {
    EntityHandle entityHandle = getEntity().getHandle();
    float mass;
    Panda::ExternalCalls::rigidbody2DComponent_GetMass(entityHandle.id, &mass);
    return mass;
}

float Rigidbody2DComponent::getFriction() {
    EntityHandle entityHandle = getEntity().getHandle();
    float friction;
    Panda::ExternalCalls::rigidbody2DComponent_GetFriction(entityHandle.id, &friction);
    return friction;
}

void Rigidbody2DComponent::setFriction(float friction) {
    EntityHandle entityHandle = getEntity().getHandle();
    Panda::ExternalCalls::rigidbody2DComponent_SetFriction(entityHandle.id, friction);
}

} // namespace Bamboo
