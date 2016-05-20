#include <stdio.h>
#include <stdlib.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

void 
mouseMove( int x, int y )
{
    Display *displayMain = XOpenDisplay(NULL);

    if(displayMain == NULL)
    {
        fprintf(stderr, "Errore nell'apertura del Display !!!\n");
        exit(EXIT_FAILURE);
    }

    XWarpPointer(displayMain, None, None, 0, 0, 0, 0, x, y);

    XCloseDisplay(displayMain);
}

int 
main( void ) {
	mouseMove(40, 40);
	return (0);
}

