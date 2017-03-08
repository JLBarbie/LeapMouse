#include "App.hpp"
#include "Systray.hpp"
#include <iostream>
#include <unistd.h>

int main(int argc, char **argv) {
    App leapmouse;
    Systray tray = Systray(argc, argv);

    return 0;
}
