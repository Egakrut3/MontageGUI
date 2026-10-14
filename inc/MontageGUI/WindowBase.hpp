#ifndef MONTAGE_WINDOW_BASE
#define MONTAGE_WINDOW_BASE

#include <SFML/Graphics.hpp>
#include <vector>

namespace MontageGUI {

class WindowBase : public sf::Drawable {
public:
    void draw(sf::RenderTarget &target,
              sf::RenderStates  states) const override final;

    WindowBase       &get_parent();
    WindowBase const &get_parent() const;

public:
    virtual ~WindowBase() = 0;

    virtual void press(sf::Vector2f point) = 0;

protected:
    explicit WindowBase();
    explicit WindowBase(WindowBase *parent);

    WindowBase(WindowBase const &)            = delete;
    WindowBase &operator=(WindowBase const &) = delete;

    virtual void draw_self(sf::RenderTarget &target,
                           sf::RenderStates  states) const = 0;

protected:
    std::vector<WindowBase *> children_;

private:
    WindowBase *parent_;
};

} // namespace MontageGUI

#endif
