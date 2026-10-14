#ifndef MONTAGE_SCENE_SHAPE
#define MONTAGE_SCENE_SHAPE

#include "MontageGUI/WindowBase.hpp"

namespace MontageGUI {

class SceneShape : public WindowBase {
public:
    void set_selected(bool is_selected);
    bool selected() const;

    void draw_self(sf::RenderTarget &target,
                   sf::RenderStates  states) const override final;

    void press(sf::Vector2f point) override final;

public:
    ~SceneShape() override = 0;

    virtual sf::Shape       &get_shape()       = 0;
    virtual sf::Shape const &get_shape() const = 0;

    virtual bool contains(sf::Vector2f point) = 0;

protected:
    explicit SceneShape(WindowBase *parent);

private:
    bool is_selected_;
};

} // namespace MontageGUI

#endif
