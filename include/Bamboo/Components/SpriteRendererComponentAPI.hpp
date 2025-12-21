#pragma once

#include "Bamboo/Base.hpp"

namespace Bamboo {

namespace SpriteRendererComponentAPI {
    Color getColor(EntityHandle entity);
    void setColor(EntityHandle entity, Color color);
    void setCell(EntityHandle entity, int cols, int rows, int index);
    void setMaterial(EntityHandle entity, MaterialHandle material);
    MaterialHandle getMaterial(EntityHandle entity);
}; // namespace SpriteRendererComponentAPI

} // namespace Bamboo