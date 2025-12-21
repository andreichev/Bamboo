#include "Bamboo/Assets/MaterialAPI.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

namespace MaterialAPI {
    void setFloat(MaterialHandle handle, const char *name, float value) {
        Panda::ExternalCalls::material_SetFloatValue(handle.id, name, value);
    }

    void setColor(MaterialHandle handle, const char *name, Color color) {
        Panda::ExternalCalls::material_SetVec4Value(
            handle.id, name, color.r, color.g, color.b, color.a
        );
    }

    void setTexture(MaterialHandle handle, const char *name, TextureHandle texture) {
        Panda::ExternalCalls::material_SetTextureValue(handle.id, name, texture.id);
    }
} // namespace MaterialAPI

} // namespace Bamboo