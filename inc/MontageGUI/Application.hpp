#ifndef MONTAGE_APPLICATION
#define MONTAGE_APPLICATION

#include "MontageGUI/Scene.hpp"

namespace MontageGUI {

class Application {
public:
    explicit Application();
    ~Application();

    bool one_more_iteration();

private:
    sf::RenderWindow window_;
    std::optional<sf::Vector2f> drag_start_;

    Scene scene_;
};

} // namespace MontageGUI

#endif
