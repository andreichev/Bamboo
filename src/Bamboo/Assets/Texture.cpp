#include "Bamboo/Assets/Texture.hpp"

namespace Bamboo {

Texture::Texture()
    : m_handle(0) {}

Texture::Texture(TextureHandle handle)
    : m_handle(handle) {}

} // namespace Bamboo