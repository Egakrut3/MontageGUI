#ifndef MONTAGE_SCENE
#define MONTAGE_SCENE

#include "MontageGUI/SceneShape.hpp"
#include <vector>

namespace MontageGUI {

class Scene : public sf::Drawable {
public:
    explicit Scene();
    ~Scene();

    void process_press(sf::Vector2f point);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void add_shape(SceneShape *shape);

private:
    std::vector<SceneShape *> objects_;
};

} // namespace MontageGUI

#endif
