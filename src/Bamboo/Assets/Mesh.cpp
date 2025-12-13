#include "Bamboo/Assets/Mesh.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

Mesh::Mesh()
    : m_handle(0) {}

Mesh::Mesh(MeshHandle handle)
    : m_handle(handle) {}

void Mesh::update(const MeshData &data) {
    Panda::ExternalCalls::mesh_Update(
        m_handle.id,
        data.vertices.data(),
        data.vertices.size(),
        data.indices.data(),
        data.indices.size()
    );
}

void Mesh::setMaterial(Material material) {
    Panda::ExternalCalls::mesh_SetMaterial(m_handle.id, material.getHandle().id);
}

} // namespace Bamboo