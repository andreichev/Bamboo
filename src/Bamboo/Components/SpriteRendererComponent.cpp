#include "Bamboo/Components/SpriteRendererComponent.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

Color SpriteRendererComponent::getColor() {
    EntityHandle entityHandle = getEntity().getHandle();
    Color result;
    Panda::ExternalCalls::spriteRendererComponent_GetColor(
        entityHandle.id, &result.r, &result.g, &result.b, &result.a
    );
    return result;
}

void SpriteRendererComponent::setColor(Color color) {
    EntityHandle entityHandle = getEntity().getHandle();
    Panda::ExternalCalls::spriteRendererComponent_SetColor(
        entityHandle.id, color.r, color.g, color.b, color.a
    );
}

void SpriteRendererComponent::setCell(int cols, int rows, int index) {
    EntityHandle entityHandle = getEntity().getHandle();
    Panda::ExternalCalls::spriteRendererComponent_SetCell(entityHandle.id, cols, rows, index);
}

void SpriteRendererComponent::setMaterial(Material material) {
    EntityHandle entityHandle = getEntity().getHandle();
    Panda::ExternalCalls::spriteRendererComponent_SetMaterial(
        entityHandle.isValid(), material.getHandle().id
    );
}

Material SpriteRendererComponent::getMaterial() {
    EntityHandle entityHandle = getEntity().getHandle();
    Panda::Handle handle = 0;
    Panda::ExternalCalls::spriteRendererComponent_GetMaterial(entityHandle.id, &handle);
    return Material(handle);
}

} // namespace Bamboo
