#include "MontageGUI/SceneShape.hpp"

namespace MontageGUI {

SceneShape::SceneShape() : sf::Drawable{}, Button{}, is_selected_{} {}
SceneShape::~SceneShape() = default;

void SceneShape::set_selected(bool const is_selected) {
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
