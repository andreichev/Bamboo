#include "Bamboo/WorldAPI.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

namespace WorldAPI {
    EntityHandle findByTag(const char *tag) {
        return Panda::ExternalCalls::world_FindByTag(tag);
    }

    EntityHandle createEntity(const char *tag) {
        return Panda::ExternalCalls::world_CreateEntity(tag);
    }

    void destroyEntity(EntityHandle entityHandle) {
        Panda::ExternalCalls::world_DestroyEntity(entityHandle.id);
    }
} // namespace WorldAPI

} // namespace Bamboo