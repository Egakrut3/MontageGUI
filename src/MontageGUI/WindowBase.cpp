#include "MontageGUI/WindowBase.hpp"

namespace MontageGUI {

WindowBase::WindowBase() : sf::Drawable{}, children_{}, parent_{} {}
WindowBase::WindowBase(WindowBase *const parent) :
    sf::Drawable{}, children_{}, parent_{parent} {}
WindowBase::~WindowBase() {
    for (WindowBase *const child : children_) {
        delete child;
    }
}

void WindowBase::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    draw_self(target, states);
    for (WindowBase const *const child : children_) {
        child->draw(target, states);
    }
}

WindowBase &WindowBase::get_parent() {
    return *parent_;
}
WindowBase const &WindowBase::get_parent() const {
    return *parent_;
}

} // namespace MontageGUI
