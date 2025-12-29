#pragma once

#include "Bamboo/Base.hpp"

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

namespace MeshAPI {
    void update(MeshHandle handle, const MeshData &data);
}; // namespace MeshAPI

} // namespace Bamboo