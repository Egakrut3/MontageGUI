#ifndef MONTAGE_SCENE_RECTANGLE
#define MONTAGE_SCENE_RECTANGLE

#include "MontageGUI/SceneShape.hpp"

namespace MontageGUI {

class SceneRectangle : public SceneShape {
public:
    explicit SceneRectangle(WindowBase  *parent,
                            sf::Vector2f size = sf::Vector2f{});
    ~SceneRectangle() override final;

    sf::Shape       &get_shape() override final;
    sf::Shape const &get_shape() const override final;

    bool contains(sf::Vector2f point) override final;

private:
    sf::RectangleShape interior_;
};

} // namespace MontageGUI

#endif
