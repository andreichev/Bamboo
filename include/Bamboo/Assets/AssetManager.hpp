#pragma once

#include "Bamboo/Base.hpp"
#include "Bamboo/Assets/Mesh.hpp"

namespace Bamboo {

namespace AssetManager {
    Mesh createMesh();
    void deleteMesh(Mesh mesh);
} // namespace AssetManager

} // namespace Bamboo