#ifndef MONTAGE_SCENE_RECTANGLE
#define MONTAGE_SCENE_RECTANGLE

#include "MontageGUI/SceneShape.hpp"

namespace MontageGUI {

class SceneRectangle : public SceneShape {
public:
    explicit SceneRectangle(sf::Vector2f size = sf::Vector2f{});
    ~SceneRectangle() override;

    void press() override;

    bool contains(sf::Vector2f point) override;

    sf::Shape       &get_shape() override;
    sf::Shape const &get_shape() const override;

private:
    sf::RectangleShape interior_;
};

} // namespace MontageGUI

#endif
