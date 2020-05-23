#include "clickLibrary.h"

bool isWindowClicked(WINDOW *win, MEVENT event)
{
    int winXmin = getbegx(win);
    int winXmax = getmaxx(win);
    int winYmin = getbegy(win);
    int winYmax = getmaxy(win);

    int mx = event.x;
    int my = event.y;

    return (mx > winXmin && mx < (winXmin + winXmax) && my > winYmin && my < (winYmin + winYmax));
}