#include "Bamboo/Assets/AssetManagerAPI.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

namespace AssetManagerAPI {
    MeshHandle createMesh() {
        Panda::Handle meshHandle;
        Panda::ExternalCalls::mesh_Create(&meshHandle);
        return MeshHandle(meshHandle);
    }

    void deleteMesh(MeshHandle mesh) {
        Panda::ExternalCalls::mesh_Delete(mesh.id);
    }

} // namespace AssetManagerAPI

} // namespace Bamboo