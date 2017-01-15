#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "Mouse.hpp"

void
mouseMove( int x, int y )
{
    Display *displayMain = XOpenDisplay(NULL);

    if(displayMain == NULL)
    {
        std::cerr << "Error Display !" << std::endl;
        exit(EXIT_FAILURE);
    }

    XWarpPointer(displayMain, None, None, 0, 0, 0, 0, x, y);

    XCloseDisplay(displayMain);
}
