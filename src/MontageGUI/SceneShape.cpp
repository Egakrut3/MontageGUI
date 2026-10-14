#include "MontageGUI/SceneShape.hpp"

namespace MontageGUI {

SceneShape::SceneShape(WindowBase *const parent) :
    WindowBase{parent}, is_selected_{} {}
SceneShape::~SceneShape() = default;

void SceneShape::set_selected(bool const is_selected) {
    is_selected_ = is_selected;
}
bool SceneShape::selected() const {
    return is_selected_;
}

void SceneShape::draw_self(sf::RenderTarget      &target,
                           sf::RenderStates const states) const {
    target.draw(get_shape(), states);
}

void SceneShape::press(sf::Vector2f const point [[maybe_unused]]) {
    if (selected()) {
        get_shape().setOutlineThickness(0);
        set_selected(false);
    }
    else {
        constexpr float SELECTED_OUTLINE_THICKNESS = 4;
        get_shape().setOutlineThickness(SELECTED_OUTLINE_THICKNESS);
        get_shape().setOutlineColor(sf::Color::Yellow);
        set_selected(true);
    }
}

} // namespace MontageGUI
