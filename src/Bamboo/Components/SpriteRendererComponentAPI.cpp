#include "Bamboo/Components/SpriteRendererComponentAPI.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

namespace SpriteRendererComponentAPI {
    Color getColor(EntityHandle entity) {
        Color result;
        Panda::ExternalCalls::spriteRendererComponent_GetColor(
            entity.id, &result.r, &result.g, &result.b, &result.a
        );
        return result;
    }

    void setColor(EntityHandle entity, Color color) {
        Panda::ExternalCalls::spriteRendererComponent_SetColor(
            entity.id, color.r, color.g, color.b, color.a
        );
    }

    void setCell(EntityHandle entity, int cols, int rows, int index) {
        Panda::ExternalCalls::spriteRendererComponent_SetCell(entity.id, cols, rows, index);
    }

    void setMaterial(EntityHandle entity, MaterialHandle material) {
        Panda::ExternalCalls::spriteRendererComponent_SetMaterial(entity.isValid(), material.id);
    }

    MaterialHandle getMaterial(EntityHandle entity) {
        Panda::Handle handle = 0;
        Panda::ExternalCalls::spriteRendererComponent_GetMaterial(entity.id, &handle);
        return MaterialHandle(handle);
    }
} // namespace SpriteRendererComponentAPI

} // namespace Bamboo
