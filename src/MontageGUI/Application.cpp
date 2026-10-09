#include "MontageGUI/Application.hpp"

namespace MontageGUI {

Application::Application() : window_{sf::VideoMode{sf::Vector2u{1280, 800}}, "test window"}, drag_start_{}, scene_{} {}
Application::~Application() = default;

bool Application::one_more_iteration() {
    if (!window_.isOpen()) {
        return false;
    }

    while (std::optional<sf::Event> event{window_.pollEvent()}) {

        if (event->is<sf::Event::Closed>()) {
            window_.close();
            return false;
        }

        if (sf::Event::MouseButtonPressed *event_info{event->getIf<sf::Event::MouseButtonPressed>()}) {
            if (!drag_start_) {
                drag_start_ = window_.mapPixelToCoords(event_info->position);
            }
        }

        if (sf::Event::MouseButtonReleased *event_info{event->getIf<sf::Event::MouseButtonReleased>()}) {
            if (drag_start_) {
                SceneRectangle *rect{new SceneRectangle{window_.mapPixelToCoords(event_info->position) - *drag_start_}};
                rect->get_shape().setPosition(*drag_start_);
                scene_.add_shape(rect);

                drag_start_.reset();
            }
        }
    }



    window_.clear();

    window_.draw(scene_);

    if (drag_start_) {
        SceneRectangle rect{window_.mapPixelToCoords(sf::Mouse::getPosition(window_)) - *drag_start_};
        rect.get_shape().setPosition(*drag_start_);
        window_.draw(rect);
    }

    window_.display();



    return true;
}

} // namespace MontageGUI
