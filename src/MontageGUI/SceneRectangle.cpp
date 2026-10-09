#include "MontageGUI/SceneRectangle.hpp"

namespace MontageGUI {

SceneRectangle::SceneRectangle(sf::Vector2f const size) :
    SceneShape{}, interior_{size} {
    interior_.setFillColor(sf::Color(0, 0xFF, 0, 0x80));
}
SceneRectangle::~SceneRectangle() = default;

void SceneRectangle::press() {
    set_selected(!selected());
}

sf::Shape &SceneRectangle::get_shape() {
    return interior_;
}
sf::Shape const &SceneRectangle::get_shape() const {
    return interior_;
}

} // namespace MontageGUI
