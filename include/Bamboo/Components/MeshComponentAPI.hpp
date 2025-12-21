#pragma once

#include "Bamboo/Base.hpp"

namespace Bamboo {

namespace MeshComponentAPI {
    void setMesh(EntityHandle entity, MeshHandle mesh);
    MeshHandle getMesh(EntityHandle entity);
}; // namespace MeshComponentAPI

} // namespace Bamboo