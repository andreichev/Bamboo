#include "Bamboo/ApplicationAPI.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

namespace ApplicationAPI {
    uint32_t getWidth() {
        return Panda::ExternalCalls::application_GetWidth();
    }

    uint32_t getHeight() {
        return Panda::ExternalCalls::application_GetHeight();
    }

    void loadWorld(const char *name) {
        Panda::ExternalCalls::world_Load(name);
    }

    bool isCursorLocked() {
        return Panda::ExternalCalls::application_IsCursorLocked();
    }

    void toggleCursorLock() {
        Panda::ExternalCalls::application_ToggleCursorLock();
    }

    void quit() {
        Panda::ExternalCalls::application_Quit();
    }
} // namespace ApplicationAPI

} // namespace Bamboo