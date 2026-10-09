#include "MontageGUI/SceneShape.hpp"

namespace MontageGUI {

SceneShape::SceneShape() : sf::Drawable{}, Button{}, is_selected_{} {}
SceneShape::~SceneShape() = default;

void SceneShape::set_selected(bool const is_selected) {
    if (is_selected) {
        constexpr float SELECTED_OUTLINE_THICKNESS = 4;
        get_shape().setOutlineThickness(SELECTED_OUTLINE_THICKNESS);
        get_shape().setOutlineColor(sf::Color::Yellow);
    }
    else {
        get_shape().setOutlineThickness(0);
    }

    is_selected_ = is_selected;
}
bool SceneShape::selected() const {
    return is_selected_;
}

void SceneShape::draw(sf::RenderTarget      &target,
                      sf::RenderStates const states) const {
    target.draw(get_shape(), states);
}

} // namespace MontageGUI
