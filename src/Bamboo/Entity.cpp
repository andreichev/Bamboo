#include "Bamboo/Entity.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

Entity::Entity()
    : m_handle(0) {}

Entity::Entity(EntityHandle handle)
    : m_handle(handle) {}

const char *Entity::getName() {
    return Panda::ExternalCalls::entity_GetName(m_handle.id);
}

} // namespace Bamboo