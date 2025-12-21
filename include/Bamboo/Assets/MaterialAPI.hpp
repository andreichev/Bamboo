#pragma once

#include "Bamboo/Base.hpp"

namespace Bamboo {

namespace MaterialAPI {
    void setFloat(MaterialHandle handle, const char *name, float value);
    void setColor(MaterialHandle handle, const char *name, Color color);
    void setTexture(MaterialHandle handle, const char *name, TextureHandle texture);
}; // namespace MaterialAPI

} // namespace Bamboo