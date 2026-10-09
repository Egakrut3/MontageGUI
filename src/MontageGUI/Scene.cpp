#include "MontageGUI/Scene.hpp"

namespace MontageGUI {

Scene::Scene() : objects_{} {}
Scene::~Scene() {
    for (SceneShape *const obj : objects_) {
        delete obj;
    }
}

void Scene::process_press(sf::Vector2f const point) {
    for (std::vector<SceneShape *>::reverse_iterator it = objects_.rbegin();
         it != objects_.rend(); ++it) {
        if ((*it)->contains(point)) {
            (*it)->press();
            break;
        }
    }
}

void Scene::draw(sf::RenderTarget      &target,
                 sf::RenderStates const states) const {
    for (SceneShape const *const obj : objects_) {
        target.draw(*obj, states);
    }
}

void Scene::add_shape(SceneShape *const shape) {
    objects_.push_back(shape);
}

} // namespace MontageGUI
