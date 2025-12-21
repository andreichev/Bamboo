#pragma once

#include "Bamboo/Base.hpp"

namespace Bamboo {

namespace TransformComponentAPI {
    Vec3 getPosition(EntityHandle entity);
    void setPosition(EntityHandle entity, Vec3 pos);
    void translate(EntityHandle entity, Vec3 translation);
    Vec3 getRotationEuler(EntityHandle entity);
    void setRotationEuler(EntityHandle entity, Vec3 degrees);
    void rotateEuler(EntityHandle entity, Vec3 degrees);
    Quat getRotation(EntityHandle entity);
    void setRotation(EntityHandle entity, Quat rotation);
    Vec3 getScale(EntityHandle entity);
    void setScale(EntityHandle entity, Vec3 scale);
}; // namespace TransformComponentAPI

} // namespace Bamboo