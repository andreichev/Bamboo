#include "Bamboo/Components/Rigidbody2DComponent.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

void Rigidbody2DComponent::applyForce(Vec2 force) {
    Panda::EntityHandle entityHandle = getEntity().getId();
    Panda::ExternalCalls::rigidbody2DComponent_applyForce(entityHandle, force.x, force.y);
}

void Rigidbody2DComponent::applyLinearImpulse(Vec2 impulse) {
    Panda::EntityHandle entityHandle = getEntity().getId();
    Panda::ExternalCalls::rigidbody2DComponent_applyLinearImpulse(
        entityHandle, impulse.x, impulse.y
    );
}

Vec2 Rigidbody2DComponent::getLinearVelocity() {
    Panda::EntityHandle entityHandle = getEntity().getId();
    Vec2 result;
    Panda::ExternalCalls::rigidbody2DComponent_getLinearVelocity(
        entityHandle, &result.x, &result.y
    );
    return result;
}

void Rigidbody2DComponent::setLinearVelocity(Vec2 velocity) {
    Panda::EntityHandle entityHandle = getEntity().getId();
    Panda::ExternalCalls::rigidbody2DComponent_setLinearVelocity(
        entityHandle, velocity.x, velocity.y
    );
}

float Rigidbody2DComponent::getMass() {
    Panda::EntityHandle entityHandle = getEntity().getId();
    float mass;
    Panda::ExternalCalls::rigidbody2DComponent_getMass(entityHandle, &mass);
    return mass;
}

float Rigidbody2DComponent::getFriction() {
    Panda::EntityHandle entityHandle = getEntity().getId();
    float friction;
    Panda::ExternalCalls::rigidbody2DComponent_getFriction(entityHandle, &friction);
    return friction;
}

void Rigidbody2DComponent::setFriction(float friction) {
    Panda::EntityHandle entityHandle = getEntity().getId();
    Panda::ExternalCalls::rigidbody2DComponent_setFriction(entityHandle, friction);
}

} // namespace Bamboo
