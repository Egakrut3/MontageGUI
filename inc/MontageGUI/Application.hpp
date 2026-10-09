#ifndef MONTAGE_APPLICATION
#define MONTAGE_APPLICATION

#include "MontageGUI/SceneShapeType.hpp"
#include "MontageGUI/Scene.hpp"

namespace MontageGUI {

class Application {
public:
    explicit Application();
    ~Application();

    bool one_more_iteration();

private:
    SceneShape *create_drawn_shape() const;

    bool process_events();
    void refresh();

private:
    sf::RenderWindow            window_;
    SceneShapeType              current_drawn_shape_;
    std::optional<sf::Vector2f> drag_start_;

    Scene scene_;
};

} // namespace MontageGUI

#endif
