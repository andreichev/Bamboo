#pragma once

#include "Base.hpp"

#include <optional>

namespace Bamboo {

namespace WorldAPI {
    EntityHandle findByTag(const char *tag);
    EntityHandle createEntity(const char *tag);
    void destroyEntity(EntityHandle entity);
}; // namespace WorldAPI

} // namespace Bamboo