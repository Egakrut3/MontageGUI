#include "MontageGUI/SceneEllipse.hpp"
#include <cmath>

namespace MontageGUI {

SceneEllipse::SceneEllipse(WindowBase *const parent, sf::Vector2f const size,
                           std::size_t const point_count) :
    SceneShape{parent}, interior_{size.x / 2, point_count} {
    if (std::abs(size.x) > 0) {
        interior_.scale(sf::Vector2f{1, size.y / size.x});
    }

    constexpr sf::Color TRANSPARENT_RED{0xFF, 0, 0, 0x80};
    interior_.setFillColor(TRANSPARENT_RED);
}
SceneEllipse::~SceneEllipse() = default;

sf::Shape &SceneEllipse::get_shape() {
    return interior_;
}
sf::Shape const &SceneEllipse::get_shape() const {
    return interior_;
}

bool SceneEllipse::contains(sf::Vector2f point) {
    return (interior_.getGeometricCenter() -
            interior_.getInverseTransform().transformPoint(point))
               .length() <= interior_.getRadius();
}

} // namespace MontageGUI
