#pragma once

#include "Bamboo/Component.hpp"
#include "Bamboo/Material.hpp"

namespace Bamboo {

class SpriteRendererComponent final : public Component {
public:
    Color getColor();
    void setColor(Color color);
    void setCell(int cols, int rows, int index);
    void setMaterial(Material material);
};

} // namespace Bamboo