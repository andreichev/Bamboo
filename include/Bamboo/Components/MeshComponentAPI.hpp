#pragma once

#include "Bamboo/Base.hpp"

namespace Bamboo {

namespace MeshComponentAPI {
    void setMesh(EntityHandle entity, MeshHandle mesh);
    MeshHandle getMesh(EntityHandle entity);
    void setMaterial(EntityHandle entity, MaterialHandle material);
}; // namespace MeshComponentAPI

} // namespace Bamboo