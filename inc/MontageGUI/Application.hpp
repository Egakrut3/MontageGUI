#ifndef MONTAGE_APPLICATION
#define MONTAGE_APPLICATION

#include "MontageGUI/SceneShapeType.hpp"
#include "MontageGUI/Scene.hpp"

namespace MontageGUI {

class Application : public WindowBase {
public:
    explicit Application();
    ~Application() override final;

    bool one_more_iteration();

private:
    void draw_self(sf::RenderTarget &target,
                   sf::RenderStates  states) const override final;

    void press(sf::Vector2f point) override final;

    Scene       *get_scene();
    Scene const *get_scene() const;

    void create_drawn_shape();
    void destroy_drawn_shape();

    bool process_events();
    void refresh();

private:
    sf::RenderWindow            window_;
    SceneShapeType              current_drawn_shape_;
    std::optional<sf::Vector2f> drag_start_;
};

} // namespace MontageGUI

#endif
