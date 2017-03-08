#include "App.hpp"
#include "Systray.hpp"
#include "Mouse.hpp"
#include "Utils.hpp"

App::App () {
    this->controller = Leap::Controller();
    this->check();
}

App::~App () {

}

void App::check() {
    sleep(5);
    if(this->controller.isConnected()) {
        printSuccess("Connected");
        this->loop();
    } else {
        printError("Leap Motion not connected");
        exit(-1);
    }
}

void
App::getCoordX(Leap::Vector currentPosition) {
    if (currentPosition.x < -20)
        x = -1;
    else if (currentPosition.x > 20)
        x = 1;
    else
        x = 0;
}

void
App::getCoordY(Leap::Vector currentPosition) {
    if ((currentPosition.y - 250) < -20)
        y = 1;
    else if ((currentPosition.y - 250) > 20)
        y = -1;
    else
        y = 0;
}

void App::loop() {
    while (true) {
        Leap::Frame frame = this->controller.frame(); // The latest frame
        Leap::Pointable pointable = frame.pointables().frontmost();
        Leap::Vector currentPosition = pointable.tipPosition();

        getCoordX(currentPosition);
        getCoordY(currentPosition);

        mouseMove(x, y);
        usleep(100);
    }
}
