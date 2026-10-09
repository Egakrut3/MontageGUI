#include "MontageGUI/Application.hpp"

namespace MontageGUI {

inline constexpr unsigned int DEFAULT_WINDOW_WIDTH  = 1280;
inline constexpr unsigned int DEFAULT_WINDOW_HEIGHT = 800;

Application::Application() :
    window_{sf::VideoMode{
                sf::Vector2u{DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT}},
            "test window"},
    drag_start_{},
    scene_{} {}
Application::~Application() = default;

bool Application::process_events() {
    while (std::optional<sf::Event> const event = window_.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window_.close();
            return false;
        }

        if (sf::Event::MouseButtonPressed const *const event_info =
                event->getIf<sf::Event::MouseButtonPressed>()) {
            if (!drag_start_) {
                drag_start_ = window_.mapPixelToCoords(event_info->position);
            }
        }

        if (sf::Event::MouseButtonReleased const *const event_info =
                event->getIf<sf::Event::MouseButtonReleased>()) {
            if (drag_start_) {
                SceneRectangle *const rect = new SceneRectangle{
                    window_.mapPixelToCoords(event_info->position) -
                    *drag_start_};
                rect->get_shape().setPosition(*drag_start_);
                scene_.add_shape(rect);

                drag_start_.reset();
            }
        }
    }

    return true;
}

void Application::refresh() {
    window_.clear();

    window_.draw(scene_);

    if (drag_start_) {
        SceneRectangle rect{
            window_.mapPixelToCoords(sf::Mouse::getPosition(window_)) -
            *drag_start_};
        rect.get_shape().setPosition(*drag_start_);
        window_.draw(rect);
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
