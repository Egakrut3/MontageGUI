#include "MontageGUI/SceneEllipse.hpp"

namespace MontageGUI {

SceneEllipse::SceneEllipse(sf::Vector2f const size, std::size_t const point_count) :
    SceneShape{}, interior_{size.x / 2, point_count} {
    interior_.scale(sf::Vector2f{1, size.y / size.x});
    interior_.setFillColor(sf::Color(0xFF, 0, 0, 0x80));
}
SceneEllipse::~SceneEllipse() = default;

void SceneEllipse::press() {
    set_selected(!selected());
}

sf::Shape &SceneEllipse::get_shape() {
    return interior_;
}
sf::Shape const &SceneEllipse::get_shape() const {
    return interior_;
}

} // namespace MontageGUI
