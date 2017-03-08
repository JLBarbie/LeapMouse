#ifndef APP_HPP
#define APP_HPP

#include <Leap.h>

class App {
    Leap::Controller controller;
    double x;
    double y;

public:
    App();
    ~App();

    void loop();
    void check();

private:
    void getCoordX(Leap::Vector);
    void getCoordY(Leap::Vector);
};

#endif
