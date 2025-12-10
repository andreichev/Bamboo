#include "Bamboo/Assets/Mesh.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

Mesh::Mesh(MeshHandle handle)
    : m_handle(handle) {}

void Mesh::setMaterial(Material material) {
    // Panda::ExternalCalls::mesh_setMaterial(m_handle.id, material->getHandle().id);
}

} // namespace Bamboo