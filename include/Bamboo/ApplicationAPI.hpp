#pragma once

#include <cstdint>

namespace Bamboo {

namespace ApplicationAPI {
    uint32_t getWidth();
    uint32_t getHeight();
    void loadWorld(const char *name);
    bool isCursorLocked();
    void toggleCursorLock();
    void quit();
}; // namespace ApplicationAPI

} // namespace Bamboo