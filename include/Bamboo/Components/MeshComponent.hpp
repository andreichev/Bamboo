#pragma once

#include "Bamboo/Component.hpp"
#include "Bamboo/Assets/Mesh.hpp"

namespace Bamboo {

class MeshComponent final : public Component {
public:
    void setMesh(Mesh mesh);
    Mesh getMesh();
};

} // namespace Bamboo