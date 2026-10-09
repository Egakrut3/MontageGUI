#include "MontageGUI/SceneEllipse.hpp"
#include <cmath>

namespace MontageGUI {

inline constexpr std::uint8_t FULL_BYTE_MASK = 0xFF;
inline constexpr std::uint8_t HIGH_BIT_MASK  = 0x80;

SceneEllipse::SceneEllipse(Application *const ptr, sf::Vector2f const size,
                           std::size_t const point_count) :
    SceneShape{ptr}, interior_{size.x / 2, point_count} {
    if (std::abs(size.x) > 0) {
        interior_.scale(sf::Vector2f{1, size.y / size.x});
    }
    interior_.setFillColor(sf::Color(FULL_BYTE_MASK, 0, 0, HIGH_BIT_MASK));
}
SceneEllipse::~SceneEllipse() = default;

bool SceneEllipse::contains(sf::Vector2f point) {
    return (interior_.getGeometricCenter() -
            interior_.getInverseTransform().transformPoint(point))
               .length() <= interior_.getRadius();
}

sf::Shape &SceneEllipse::get_shape() {
    return interior_;
}
sf::Shape const &SceneEllipse::get_shape() const {
    return interior_;
}

} // namespace MontageGUI
