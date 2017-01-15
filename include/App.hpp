#ifndef APP_HPP
#define APP_HPP

#include <Leap.h>
#include "Util.hpp"

class App
{
    Leap::Controller controller;

public:
    App();
    ~App();

    void loop();
    void check();
};

#endif
