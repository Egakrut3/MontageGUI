#ifndef MONTAGE_SCENE_ELLIPSE
#define MONTAGE_SCENE_ELLIPSE

#include "MontageGUI/SceneShape.hpp"

namespace MontageGUI {

class SceneEllipse : public SceneShape {
public:
    static constexpr std::size_t DEFAULT_POINT_COUNT = 30;
    explicit SceneEllipse(sf::Vector2f size,
                          std::size_t  point_count = DEFAULT_POINT_COUNT);
    ~SceneEllipse() override;

    void press() override;

    sf::Shape       &get_shape() override;
    sf::Shape const &get_shape() const override;

private:
    sf::CircleShape interior_;
};

} // namespace MontageGUI

#endif
