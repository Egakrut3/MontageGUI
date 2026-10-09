#include "MontageGUI/SceneShapeType.hpp"

namespace MontageGUI {

SceneShapeType &operator++(SceneShapeType &state) {
    state = static_cast<SceneShapeType>(static_cast<int>(state) + 1);
    if (state == SceneShapeType::ENUM_SIZE) {
        state = SceneShapeType::NOTHING;
    }

    return state;
}

} // namespace MontageGUI
