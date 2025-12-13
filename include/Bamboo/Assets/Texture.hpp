#pragma once

#include "Bamboo/Base.hpp"

namespace Bamboo {

class Texture final {
public:
    Texture();
    Texture(TextureHandle handle);

    bool isValid() {
        return m_handle.isValid();
    }

    TextureHandle getHandle() {
        return m_handle;
    }

private:
    TextureHandle m_handle;
};

} // namespace Bamboo