#include <ncurses.h>
#include <unistd.h>

#define OPTION_NUMS 3

void blinkText(WINDOW* win, int y, int x, char* text, int blinkNum);

int main(int argc, char const *argv[])
{
    initscr();
    curs_set(0);
    refresh();

    int height = 10, width = 50;

    WINDOW *menu = newwin(height, width, 5, 10);
    box(menu, 0, 0);
    wrefresh(menu);

    printw("menu curY = %d, maxY = %d\n", getcury(menu), getmaxy(menu));
    printw("menu parY = %d, begY = %d\n", getpary(menu), getbegy(menu));
    printw("menu parX = %d, begX = %d\n", getparx(menu), getbegx(menu));

    refresh();

    char *menuOptions[OPTION_NUMS] = {"Steve Jobs", "David Bowie", "Elon Musk"};
    printw("%d", sizeof(menuOptions));
    refresh();

    for (int i = 0; i < 3; i++)
    {
        mvwprintw(menu, 1 + i, 2, menuOptions[i]);
    }

    wrefresh(menu);
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


void blinkText(WINDOW* win, int y, int x, char* text, int blinkNum){
    while(blinkNum > 0 ){
        wattron(win, A_REVERSE);
        wattron(win, A_BOLD);
        mvwprintw(win, y, x, text);
        wrefresh(win);
        usleep(100000);

        wattroff(win, A_REVERSE);
        wattroff(win, A_BOLD);
        mvwprintw(win, y, x, text);
        wrefresh(win);
        usleep(100000);

        blinkNum--;
    }
}