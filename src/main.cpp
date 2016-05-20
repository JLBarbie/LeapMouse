#include <Leap.h>
#include <iostream>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

using namespace Leap;

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

int main(int argc, char const *argv[])
{
	double x;
	double y;


	Controller controller;
	std::cout << "Connected" << std::endl;
	while (true) {
		Leap::Frame frame = controller.frame(); //The latest frame
    	Leap::Pointable pointable = frame.pointables().frontmost();
    	Vector currentPosition = pointable.tipPosition();
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
	return 0;
}