#include "Bamboo/Components/TransformComponentAPI.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

namespace TransformComponentAPI {
    Vec3 getPosition(EntityHandle entity) {
        Vec3 result;
        Panda::ExternalCalls::transformComponent_GetPosition(
            entity.id, &result.x, &result.y, &result.z
        );
        return result;
    }

    void setPosition(EntityHandle entity, Vec3 pos) {
        Panda::ExternalCalls::transformComponent_SetPosition(entity.id, pos.x, pos.y, pos.z);
    }

    void translate(EntityHandle entity, Vec3 translation) {
        Panda::ExternalCalls::transformComponent_Translate(
            entity.id, translation.x, translation.y, translation.z
        );
    }

    Vec3 getRotationEuler(EntityHandle entity) {
        Vec3 result;
        Panda::ExternalCalls::transformComponent_GetRotationEuler(
            entity.id, &result.x, &result.y, &result.z
        );
        return result;
    }

    void setRotationEuler(EntityHandle entity, Vec3 degrees) {
        Panda::ExternalCalls::transformComponent_SetRotationEuler(
            entity.id, degrees.x, degrees.y, degrees.z
        );
    }

    void rotateEuler(EntityHandle entity, Vec3 degrees) {
        Panda::ExternalCalls::transformComponent_RotateEuler(
            entity.id, degrees.x, degrees.y, degrees.z
        );
    }

    Quat getRotation(EntityHandle entity) {
        Quat result;
        Panda::ExternalCalls::transformComponent_GetRotation(
            entity.id, &result.w, &result.x, &result.y, &result.z
        );
        return result;
    }

    void setRotation(EntityHandle entity, Quat rotation) {
        Panda::ExternalCalls::transformComponent_SetRotation(
            entity.id, rotation.w, rotation.x, rotation.y, rotation.z
        );
    }

    Vec3 getScale(EntityHandle entity) {
        Vec3 result;
        Panda::ExternalCalls::transformComponent_GetScale(
            entity.id, &result.x, &result.y, &result.z
        );
        return result;
    }

    void setScale(EntityHandle entity, Vec3 scale) {
        Panda::ExternalCalls::transformComponent_SetScale(entity.id, scale.x, scale.y, scale.z);
    }
} // namespace TransformComponentAPI

} // namespace Bamboo
