#ifndef MONTAGE_COMMON
#define MONTAGE_COMMON

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
