#include "App.hpp"
#include "Systray.hpp"
#include "Mouse.hpp"
#include "Utils.hpp"

#define PRECISION 30

App::App () {
    this->controller = Leap::Controller();
    this->controller.enableGesture(Leap::Gesture::TYPE_KEY_TAP);
    this->check();
}

App::~App () {

}

void
App::check() {
    sleep(2);
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
    if (currentPosition.x < -PRECISION)
        x = -1;
    else if (currentPosition.x > PRECISION)
        x = 1;
    else
        x = 0;
}

void
App::getCoordY(Leap::Vector currentPosition) {
    if ((currentPosition.y - 250) < -PRECISION)
        y = 1;
    else if ((currentPosition.y - 250) > PRECISION)
        y = -1;
    else
        y = 0;
}

void
App::loop() {
    while (true) {
        Leap::Frame frame = this->controller.frame(); // The latest frame
        Leap::Pointable pointable = frame.pointables().frontmost();
        Leap::Vector currentPosition = pointable.tipPosition();

        checkGesture();
        usleep(1000);
        getCoordX(currentPosition);
        getCoordY(currentPosition);

        mouseMove(x, y);
        usleep(1000);
    }
}

void
App::checkGesture( ) {
    Leap::Frame frame = this->controller.frame();
    Leap::GestureList gestures = frame.gestures();
    for(Leap::GestureList::const_iterator gl = gestures.begin(); gl != frame.gestures().end(); gl++)
    {
        switch ((*gl).type()) {
            case Leap::Gesture::TYPE_CIRCLE:
                //Handle circle gestures
                break;
            case Leap::Gesture::TYPE_KEY_TAP:
                printDebug("Click");
                mouseClick();
                break;
            case Leap::Gesture::TYPE_SCREEN_TAP:
                std::cout << "Screen Tap" << std::endl;
                break;
            case Leap::Gesture::TYPE_SWIPE:
                std::cout << "Swipe" << std::endl;
                break;
            default:
                //Handle unrecognized gestures
                break;
        }
    }
}
