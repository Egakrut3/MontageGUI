#include "MontageGUI/SceneRectangle.hpp"

namespace MontageGUI {

inline constexpr std::uint8_t FULL_BYTE_MASK = 0xFF;
inline constexpr std::uint8_t HIGH_BIT_MASK  = 0x80;

SceneRectangle::SceneRectangle(sf::Vector2f const size) :
    SceneShape{}, interior_{size} {
    interior_.setFillColor(sf::Color(0, FULL_BYTE_MASK, 0, HIGH_BIT_MASK));
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
