#include <ncurses.h>
#include "ncEffect.h"
#include "ncComponent.h"

#define OPTION_NUMS 3

int main(int argc, char const *argv[])
{
    initscr();
    curs_set(0);
    refresh();

    int height = 10, width = 50;
    char *menuOptions[OPTION_NUMS] = {"Steve Jobs", "David Bowie", "Elon Musk"};

    WINDOW* menu = createMenu(
        height,
        width,
        5,
        10,
        menuOptions,
        OPTION_NUMS
    );

    printw("menu curY = %d, maxY = %d\n", getcury(menu), getmaxy(menu));
    printw("menu parY = %d, begY = %d\n", getpary(menu), getbegy(menu));
    printw("menu parX = %d, begX = %d\n", getparx(menu), getbegx(menu));

    refresh();
    
    MEVENT mouseEvnet;

    // deal with input config
    noecho();
    keypad(menu, true);
    mousemask(ALL_MOUSE_EVENTS, NULL);

    while (1)
    {
        int ch = wgetch(menu);
        if (ch == KEY_MOUSE)
        {
            getmouse(&mouseEvnet);
            if (mouseEvnet.bstate & BUTTON1_CLICKED)
            {
                int winBegY = getbegy(menu);
                int winMaxY = getmaxy(menu);

                int winBegX = getbegx(menu);
                int winMaxX = getmaxx(menu);

                int y = mouseEvnet.y;
                int x = mouseEvnet.x;

                if (y > winBegY && y < (winBegY + winMaxY) &&
                    x > winBegX && x < (winBegX + winMaxX))
                {
                    int relativePositionY = y - winBegY;
                    int index = relativePositionY - 1;
                    if( index < OPTION_NUMS){
                        mvwprintw(menu, 7, 2, "You click option [%d]", index);
                        blinkText(menu, 1 + index, 2, menuOptions[index], 3);
                    }
                }

                mvwprintw(menu, 8, 2, "You clicked at positon [%d,%d]", mouseEvnet.x, mouseEvnet.y);
                wrefresh(menu);
            }
        }
    }
    endwin();

    return 0;
}