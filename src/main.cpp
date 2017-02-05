
#include "App.hpp"
#include "Systray.hpp"
#include <iostream>
#include <unistd.h>

int main(int argc, char **argv) {
    Systray tray = Systray(argc, argv);
    App leapmouse;

    return 0;
}
