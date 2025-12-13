#include "Bamboo/Assets/AssetManager.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

namespace AssetManager {
    Mesh createMesh() {
        Panda::Handle meshHandle;
        Panda::ExternalCalls::mesh_Create(&meshHandle);
        return Mesh(meshHandle);
    }

    void deleteMesh(Mesh mesh) {
        Panda::ExternalCalls::mesh_Delete(mesh.getHandle().id);
    }

} // namespace AssetManager

} // namespace Bamboo