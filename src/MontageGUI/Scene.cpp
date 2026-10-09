#include "MontageGUI/Scene.hpp"

namespace MontageGUI {

SceneShape::SceneShape() : sf::Drawable{}, Button{}, is_selected_{} {}
SceneShape::~SceneShape() = default;

void SceneShape::set_selected(bool const is_selected) {
    is_selected_ = is_selected;
}
bool SceneShape::selected() const {
    return is_selected_;
}

void SceneShape::draw(sf::RenderTarget &target, sf::RenderStates const states) const {
    target.draw(get_shape(), states);
}



SceneRectangle::SceneRectangle(sf::Vector2f const &size) : SceneShape{}, interior_{size} {
    interior_.setFillColor(sf::Color::Green);
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



Scene::Scene() : objects_{} {}
Scene::~Scene() {
    for (SceneShape *obj : objects_) {
        delete obj;
    }
}

void Scene::draw(sf::RenderTarget &target, sf::RenderStates const states) const {
    for (SceneShape const *obj : objects_) {
        obj->draw(target, states);
    }
}

void Scene::add_shape(SceneShape *const shape) {
    objects_.push_back(shape);
}

} // namespace MontageGUI
