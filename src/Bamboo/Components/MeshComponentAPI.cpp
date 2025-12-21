#include "Bamboo/Components/MeshComponentAPI.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

namespace MeshComponentAPI {
    MeshHandle getMesh(EntityHandle entity) {
        Panda::Handle result;
        Panda::ExternalCalls::meshComponent_GetMesh(entity.id, &result);
        return MeshHandle(result);
    }

    void setMesh(EntityHandle entity, MeshHandle mesh) {
        Panda::ExternalCalls::meshComponent_SetMesh(entity.id, mesh.id);
    }
} // namespace MeshComponentAPI

} // namespace Bamboo