#pragma once

#include "Bamboo/Base.hpp"
#include "Bamboo/Assets/Texture.hpp"

namespace Bamboo {

class Material final {
public:
    Material(MaterialHandle handle);

    bool isValid() {
        return m_handle.isValid();
    }

    MaterialHandle getHandle() {
        return m_handle;
    }

    void setFloat(const char *name, float value);
    void setColor(const char *name, Color color);
    void setTexture(const char *name, Texture texture);

private:
    MaterialHandle m_handle;
};

} // namespace Bamboo