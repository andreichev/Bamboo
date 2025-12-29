#include "Bamboo/Assets/MeshAPI.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

namespace MeshAPI {
    void update(MeshHandle handle, const MeshData &data) {
        Panda::ExternalCalls::mesh_Update(
            handle.id,
            data.vertices.data(),
            data.vertices.size(),
            data.indices.data(),
            data.indices.size()
        );
    }
} // namespace MeshAPI

} // namespace Bamboo