#include "MontageGUI/Application.hpp"

// TODO - Switch to value initialization {}
// TODO - restirct
// TODO - C++ modules
// TODO - How to differ between Compilation end and Build end

static void test_montage_GUI() {
    using namespace MontageGUI;

    Application app{};
    while (app.one_more_iteration()) {}
}

int main() {
    test_montage_GUI();

    return 0;
}
