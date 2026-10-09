#ifndef MONTAGE_BUTTON
#define MONTAGE_BUTTON

namespace MontageGUI {

class Application;

class Button {
public:
    virtual ~Button() = 0;

    virtual void press() = 0;

protected:
    explicit Button(Application *ptr);

protected:
    Application *ptr_;
};

} // namespace MontageGUI

#endif
