#include "MontageGUI/Scene.hpp"

namespace MontageGUI {

Scene::Scene(WindowBase *const parent) : WindowBase{parent} {}
Scene::~Scene() = default;

void Scene::press(sf::Vector2f const point) {
    for (std::vector<WindowBase *>::reverse_iterator child = children_.rbegin();
         child != children_.rend(); ++child) {
        SceneShape *const shape = static_cast<SceneShape *>(*child);
        if (shape->contains(point)) {
            shape->press(point);
            break;
        }
    }
}

void Scene::draw_self(sf::RenderTarget      &target [[maybe_unused]],
                      sf::RenderStates const states [[maybe_unused]]) const {}

void Scene::add_shape(SceneShape *const shape) {
    children_.push_back(shape);
}
void Scene::remove_last() {
    delete children_.back();
    children_.pop_back();
}

} // namespace MontageGUI
