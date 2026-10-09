#ifndef MONTAGE_SCENE_SHAPE
#define MONTAGE_SCENE_SHAPE

#include <SFML/Graphics.hpp>
#include "MontageGUI/Button.hpp"

namespace MontageGUI {

class SceneShape : public sf::Drawable, public Button {
public:
    ~SceneShape() override = 0;

    void press() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    virtual bool contains(sf::Vector2f point) = 0;

    virtual sf::Shape       &get_shape()       = 0;
    virtual sf::Shape const &get_shape() const = 0;

protected:
    explicit SceneShape();

private:
    void set_selected(bool is_selected);
    bool selected() const;

private:
    bool is_selected_;
};

} // namespace MontageGUI

#endif
