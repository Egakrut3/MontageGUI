#ifndef MONTAGE_SCENE
#define MONTAGE_SCENE

#include "MontageGUI/Common.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

namespace MontageGUI {

class SceneShape : public sf::Drawable, public Button {
public:
    ~SceneShape() override = 0;

    void set_selected(bool is_selected);
    bool selected() const;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    virtual sf::Shape       &get_shape()       = 0;
    virtual sf::Shape const &get_shape() const = 0;

protected:
    explicit SceneShape();

private:
    bool is_selected_;
};

class SceneRectangle : public SceneShape {
public:
    explicit SceneRectangle(sf::Vector2f const &size = sf::Vector2f{});
    ~SceneRectangle() override;

    void press() override;

    sf::Shape       &get_shape() override;
    sf::Shape const &get_shape() const override;

private:
    sf::RectangleShape interior_;
};

class Scene : public sf::Drawable {
public:
    explicit Scene();
    ~Scene();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void add_shape(SceneShape *shape);

private:
    std::vector<SceneShape *> objects_;
};

} // namespace MontageGUI

#endif
