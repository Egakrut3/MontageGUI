#include "MontageGUI/Application.hpp"
#include "MontageGUI/SceneRectangle.hpp"
#include "MontageGUI/SceneEllipse.hpp"
#include <cassert>

namespace MontageGUI {

inline constexpr unsigned int DEFAULT_WINDOW_WIDTH  = 1280;
inline constexpr unsigned int DEFAULT_WINDOW_HEIGHT = 800;

Application::Application() :
    window_{sf::VideoMode{
                sf::Vector2u{DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT}},
            "test window"},
    current_drawn_shape_(SceneShapeType::NOTHING),
    drag_start_{},
    scene_{} {}
Application::~Application() = default;

SceneShape *Application::create_drawn_shape() const {
    assert(drag_start_);

    SceneShape *result = nullptr;
    switch (current_drawn_shape_) {
        case SceneShapeType::NOTHING:
            return nullptr;

        case SceneShapeType::RECTANGLE:
            result = new SceneRectangle{
                window_.mapPixelToCoords(sf::Mouse::getPosition(window_)) -
                *drag_start_};
            break;

        case SceneShapeType::ELLIPSE:
            result = new SceneEllipse{
                window_.mapPixelToCoords(sf::Mouse::getPosition(window_)) -
                *drag_start_};
            break;

        case SceneShapeType::ENUM_SIZE:
        default:
            assert(false);
    }
    assert(result);

    result->get_shape().setPosition(*drag_start_);
    return result;
}

bool Application::process_events() {
    while (std::optional<sf::Event> const event = window_.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window_.close();
            return false;
        }

        if (sf::Event::KeyReleased const *const event_info =
                event->getIf<sf::Event::KeyReleased>();
            event_info != nullptr &&
            event_info->scancode == sf::Keyboard::Scancode::Tab) {
            ++current_drawn_shape_;
        }

        if (sf::Event::MouseButtonPressed const *const event_info =
                event->getIf<sf::Event::MouseButtonPressed>();
            event_info != nullptr && !drag_start_) {
            drag_start_ = window_.mapPixelToCoords(event_info->position);
        }

        if (sf::Event::MouseButtonReleased const *const event_info =
                event->getIf<sf::Event::MouseButtonReleased>();
            event_info != nullptr && drag_start_) {
            if (SceneShape *const shape = create_drawn_shape()) {
                scene_.add_shape(shape);
            }
            drag_start_.reset();
        }
    }

    return true;
}

void Application::refresh() {
    window_.clear();

    window_.draw(scene_);

    if (drag_start_) {
        if (SceneShape *const shape = create_drawn_shape()) {
            window_.draw(*shape);
            delete shape;
        }
    }

    window_.display();
}

bool Application::one_more_iteration() {
    if (!process_events()) {
        return false;
    }

    refresh();
    return true;
}

} // namespace MontageGUI
