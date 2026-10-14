#ifndef MONTAGE_SCENE
#define MONTAGE_SCENE

#include "MontageGUI/SceneShape.hpp"

namespace MontageGUI {

class Scene : public WindowBase {
public:
    explicit Scene(WindowBase *parent);
    ~Scene() override final;

    void draw_self(sf::RenderTarget &target,
                   sf::RenderStates  states) const override final;

    void press(sf::Vector2f point) override final;

    void add_shape(SceneShape *shape);
    void remove_last();
};

} // namespace MontageGUI

#endif
