#include "MontageGUI/SceneRectangle.hpp"

namespace MontageGUI {

SceneRectangle::SceneRectangle(WindowBase *const  parent,
                               sf::Vector2f const size) :
    SceneShape{parent}, interior_{size} {
    constexpr sf::Color TRANSPARENT_GREEN{0, 0xFF, 0, 0x80};
    interior_.setFillColor(TRANSPARENT_GREEN);
}
SceneRectangle::~SceneRectangle() = default;

sf::Shape &SceneRectangle::get_shape() {
    return interior_;
}
sf::Shape const &SceneRectangle::get_shape() const {
    return interior_;
}

bool SceneRectangle::contains(sf::Vector2f const point) {
    return interior_.getGlobalBounds().contains(point);
}

} // namespace MontageGUI
