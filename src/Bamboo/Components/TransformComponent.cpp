#include "Bamboo/Components/TransformComponent.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

Vec3 TransformComponent::getPosition() {
    EntityHandle entityHandle = getEntity().getHandle();
    Vec3 result;
    Panda::ExternalCalls::transformComponent_GetPosition(
        entityHandle.id, &result.x, &result.y, &result.z
    );
    return result;
}

void TransformComponent::setPosition(Vec3 pos) {
    EntityHandle entityHandle = getEntity().getHandle();
    Panda::ExternalCalls::transformComponent_SetPosition(entityHandle.id, pos.x, pos.y, pos.z);
}

Vec3 TransformComponent::getRotationEuler() {
    EntityHandle entityHandle = getEntity().getHandle();
    Vec3 result;
    Panda::ExternalCalls::transformComponent_GetRotationEuler(
        entityHandle.id, &result.x, &result.y, &result.z
    );
    return result;
}

void TransformComponent::setRotationEuler(Vec3 degrees) {
    EntityHandle entityHandle = getEntity().getHandle();
    Panda::ExternalCalls::transformComponent_SetRotationEuler(
        entityHandle.id, degrees.x, degrees.y, degrees.z
    );
}

Vec3 TransformComponent::getScale() {
    EntityHandle entityHandle = getEntity().getHandle();
    Vec3 result;
    Panda::ExternalCalls::transformComponent_GetScale(
        entityHandle.id, &result.x, &result.y, &result.z
    );
    return result;
}

void TransformComponent::setScale(Vec3 scale) {
    EntityHandle entityHandle = getEntity().getHandle();
    Panda::ExternalCalls::transformComponent_SetScale(entityHandle.id, scale.x, scale.y, scale.z);
}

} // namespace Bamboo
