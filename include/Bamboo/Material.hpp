#pragma once

#include "Bamboo/Base.hpp"
#include "Bamboo/Texture.hpp"

namespace Bamboo {

class Material final {
public:
    Material();
    Material(MaterialHandle id);

    inline bool isValid() {
        return m_id != 0;
    }

    inline uint32_t getId() {
        return m_id;
    }

    void setFloat(const char *name, float value);
    void setColor(const char *name, Color color);
    void setTexture(const char *name, Texture texture);

private:
    MaterialHandle m_id;
};

} // namespace Bamboo