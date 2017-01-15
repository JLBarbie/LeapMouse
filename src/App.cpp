#include "App.hpp"
#include "Systray.hpp"
#include "Mouse.hpp"

App::App () {
    this->check();
}

App::~App () {

}

void App::check() {
    if(this->controller.isConnected()) {
        std::cout << "[ \033[34mDONE\033[0m ] Connected" << std::endl;
        this->loop();
    } else {
        Util::printError("Leap Motion not connected");
        exit(-1);
    }
}

void App::loop() {
    double x;
    double y;

    while (true) {
        Leap::Frame frame = this->controller.frame(); // The latest frame
        Leap::Pointable pointable = frame.pointables().frontmost();
        Leap::Vector currentPosition = pointable.tipPosition();
        if (currentPosition.x < -20)
            x = -1;
        else if (currentPosition.x > 20)
            x = 1;
        else
            x = 0;

        if ((currentPosition.y - 250) < -20)
            y = 1;
        else if ((currentPosition.y - 250) > 20)
            y = -1;
        else
            y = 0;
        mouseMove(x, y);
        usleep(100);
    }
}
