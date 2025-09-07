#include "Bamboo/Material.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

Material::Material()
    : m_id(0) {}

Material::Material(MaterialHandle id)
    : m_id(id) {}

void Material::setColor(const char *name, Color color) {
    Panda::ExternalCalls::material_SetColor(m_id, name, color.r, color.g, color.b, color.a);
}

void Material::setTexture(const char *name, Texture texture) {
    Panda::ExternalCalls::material_SetTexture(m_id, name, texture.getId());
}

} // namespace Bamboo