#ifndef MONTAGE_BUTTON
#define MONTAGE_BUTTON

namespace MontageGUI {

class Button {
public:
    virtual ~Button() = 0;

    virtual void press() = 0;

protected:
    explicit Button();
};

} // namespace MontageGUI

#endif
