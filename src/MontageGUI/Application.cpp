#include "MontageGUI/Application.hpp"
#include "MontageGUI/SceneRectangle.hpp"
#include "MontageGUI/SceneEllipse.hpp"
#include <cassert>

namespace MontageGUI {

inline constexpr unsigned int DEFAULT_WINDOW_WIDTH  = 1280;
inline constexpr unsigned int DEFAULT_WINDOW_HEIGHT = 800;

Application::Application() :
    WindowBase{},
    window_{sf::VideoMode{
                sf::Vector2u{DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT}},
            "test window"},
    current_drawn_shape_(SceneShapeType::NOTHING),
    drag_start_{} {
    children_.push_back(new Scene{this});
}
Application::~Application() = default;

void Application::draw_self(sf::RenderTarget &target [[maybe_unused]],
                            sf::RenderStates  states [[maybe_unused]]) const {}

void Application::press(sf::Vector2f point) {
    if (current_drawn_shape_ == SceneShapeType::NOTHING) {
        get_scene()->press(point);
    }
    else {
        drag_start_ = point;
    }
}

Scene *Application::get_scene() {
    return static_cast<Scene *>(children_.front());
}
Scene const *Application::get_scene() const {
    return static_cast<Scene const *>(children_.front());
}

void Application::create_drawn_shape() {
    if (!drag_start_) {
        return;
    }

    SceneShape *result = nullptr;
    switch (current_drawn_shape_) {
        case SceneShapeType::NOTHING:
            return;

        case SceneShapeType::RECTANGLE:
            result = new SceneRectangle{
                get_scene(),
                window_.mapPixelToCoords(sf::Mouse::getPosition(window_)) -
                    *drag_start_};
            break;

        case SceneShapeType::ELLIPSE:
            result = new SceneEllipse{
                get_scene(),
                window_.mapPixelToCoords(sf::Mouse::getPosition(window_)) -
                    *drag_start_};
            break;

        case SceneShapeType::ENUM_SIZE:
        default:
            assert(false);
    }
    assert(result);

    result->get_shape().setPosition(*drag_start_);
    get_scene()->add_shape(result);
}
void Application::destroy_drawn_shape() {
    if (!drag_start_) {
        return;
    }

    switch (current_drawn_shape_) {
        case SceneShapeType::NOTHING:
            break;

        case SceneShapeType::RECTANGLE:
        case SceneShapeType::ELLIPSE:
            get_scene()->remove_last();
            break;

        case SceneShapeType::ENUM_SIZE:
        default:
            assert(false);
    }
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
            sf::Vector2f const point =
                window_.mapPixelToCoords(event_info->position);
            press(point);
        }

        if (sf::Event::MouseButtonReleased const *const event_info =
                event->getIf<sf::Event::MouseButtonReleased>();
            event_info != nullptr && drag_start_) {
            create_drawn_shape();
            drag_start_.reset();
        }
    }

    return true;
}
void Application::refresh() {
    window_.clear();

    create_drawn_shape();
    window_.draw(*this);
    destroy_drawn_shape();

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
