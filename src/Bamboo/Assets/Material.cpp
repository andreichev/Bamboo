#include "Bamboo/Assets/Material.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

Material::Material()
    : m_handle(0) {}

Material::Material(MaterialHandle handle)
    : m_handle(handle) {}

void Material::setFloat(const char *name, float value) {
    Panda::ExternalCalls::material_SetFloatValue(m_handle.id, name, value);
}

void Material::setColor(const char *name, Color color) {
    Panda::ExternalCalls::material_SetVec4Value(
        m_handle.id, name, color.r, color.g, color.b, color.a
    );
}

void Material::setTexture(const char *name, Texture texture) {
    Panda::ExternalCalls::material_SetTextureValue(m_handle.id, name, texture.getHandle().id);
}

} // namespace Bamboo