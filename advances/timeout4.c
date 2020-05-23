#include <ncurses.h>
#include "clickLibrary.h"

int main(int argc, char const *argv[])
{
    initscr();
    curs_set(0);
    refresh();

    keypad(stdscr, true);
    mousemask(BUTTON1_CLICKED, NULL);

    int x = 0;
    WINDOW *win = newwin(2, 2, 1, x);
    wprintw(win, "o");
    wrefresh(win);

    WINDOW *button = newwin(5, 20, 5, 2);
    box(button, 0, 0);
    mvwprintw(button, 2, 2, "Stop animation");
    wrefresh(button);

    WINDOW *buttonStart = newwin(5, 20, 12, 2);
    box(buttonStart, 0, 0);
    mvwprintw(buttonStart, 2, 2, "Start animation");
    wrefresh(buttonStart);

    timeout(100);

    while (1)
    {
        int ch = getch();

        if (ch == KEY_MOUSE)
        {
            MEVENT mouseEvent;
            getmouse(&mouseEvent);

            if( isWindowClicked(button, mouseEvent)){
                printw("You clicked at stop button");

                nodelay(stdscr, false);
            }
            else if( isWindowClicked(buttonStart, mouseEvent)){
                printw("You clicked at start button");
                timeout(100);
            }
            else
            {
                printw("You clicked mouse at [%d,%d]", mouseEvent.x, mouseEvent.y);
            }
        }

        x++;
        wclear(win);
        wrefresh(win);

        mvwin(win, 1, x);
        wprintw(win, "o");
        wrefresh(win);
    }

    nodelay(stdscr, false);
    getch();

    endwin();
    return 0;
}
