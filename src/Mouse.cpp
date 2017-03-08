#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "Utils.hpp"
#include "Mouse.hpp"

void
mouseMove( int x, int y )
{
    Display *displayMain = XOpenDisplay(NULL);

    if(displayMain == NULL)
    {
        printError("Could'nt open display");
        exit(EXIT_FAILURE);
    }

    XWarpPointer(displayMain, None, None, 0, 0, 0, 0, x, y);

    XCloseDisplay(displayMain);
}
