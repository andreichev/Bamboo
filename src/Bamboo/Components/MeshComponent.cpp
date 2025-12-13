#include "Bamboo/Components/MeshComponent.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

Mesh MeshComponent::getMesh() {
    EntityHandle entityHandle = getEntity().getHandle();
    Panda::Handle result;
    Panda::ExternalCalls::meshComponent_GetMesh(entityHandle.id, &result);
    return Mesh(result);
}

void MeshComponent::setMesh(Mesh mesh) {
    EntityHandle entityHandle = getEntity().getHandle();
    Panda::ExternalCalls::meshComponent_SetMesh(entityHandle.id, mesh.getHandle().id);
}

} // namespace Bamboo