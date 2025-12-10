#include "Bamboo/World.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

std::optional<Entity> World::findByTag(const char *tag) {
    EntityHandle entityHandle = Panda::ExternalCalls::world_FindByTag(tag);
    return Entity(entityHandle);
}

Entity World::createEntity(const char *tag) {
    EntityHandle entityHandle = Panda::ExternalCalls::world_CreateEntity(tag);
    return Entity(entityHandle);
}

void World::destroyEntity(Entity entity) {
    Panda::ExternalCalls::world_DestroyEntity(entity.m_handle.id);
}

} // namespace Bamboo