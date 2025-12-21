#include "Bamboo/Input.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

bool Input::isKeyPressed(Key key) {
    return Panda::ExternalCalls::input_IsKeyPressed((int)key);
}

bool Input::isKeyJustPressed(Key key) {
    return Panda::ExternalCalls::input_IsKeyJustPressed((int)key);
}

bool Input::isMouseButtonPressed(MouseButton mouseButton) {
    return Panda::ExternalCalls::input_IsMouseButtonPressed((int)mouseButton);
}

bool Input::isMouseButtonJustPressed(MouseButton mouseButton) {
    return Panda::ExternalCalls::input_IsMouseButtonJustPressed((int)mouseButton);
}

double Input::getMouseDeltaX() {
    return Panda::ExternalCalls::input_GetMouseDeltaX();
}

double Input::getMouseDeltaY() {
    return Panda::ExternalCalls::input_GetMouseDeltaY();
}

} // namespace Bamboo