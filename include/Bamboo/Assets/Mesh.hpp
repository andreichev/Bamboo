#pragma once

#include "Bamboo/Base.hpp"
#include "Bamboo/Assets/Material.hpp"

namespace Bamboo {

class Mesh final {
public:
    Mesh(MeshHandle handle);

    bool isValid() {
        return m_handle.isValid();
    }

    MeshHandle getHandle() {
        return m_handle;
    }

    void setMaterial(Material material);

private:
    MeshHandle m_handle;
};

} // namespace Bamboo