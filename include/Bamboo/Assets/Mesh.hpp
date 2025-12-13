#pragma once

#include "Bamboo/Base.hpp"
#include "Bamboo/Assets/Material.hpp"

#include <vector>

namespace Bamboo {

struct Vertex {
    Vec3 pos;
    Vec2 uv;
    Vec3 normal;
    Vec4 color;
    float light;
    uint32_t id;
};

struct MeshData {
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
};

class Mesh final {
public:
    Mesh();
    Mesh(MeshHandle handle);

    bool isValid() {
        return m_handle.isValid();
    }

    MeshHandle getHandle() {
        return m_handle;
    }

    void update(const MeshData &data);
    void setMaterial(Material material);

private:
    MeshHandle m_handle;
};

} // namespace Bamboo