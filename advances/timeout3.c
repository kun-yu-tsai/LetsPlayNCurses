#include <ncurses.h>

int main(int argc, char const *argv[])
{
    initscr();
    curs_set(0);

    keypad(stdscr, true);
    mousemask(ALL_MOUSE_EVENTS, NULL);

    int x = 0;
    WINDOW *win = newwin(2, 2, 1, x);
    wprintw(win, "o");
    wrefresh(win);

    timeout(100);

    while (1)
    {
        int ch = getch(); // it will timeout after 100ms

        if (ch == KEY_MOUSE)
        {
            MEVENT mouseEvent;
            getmouse(&mouseEvent);
            printw("You clicked mouse at [%d,%d]", mouseEvent.x, mouseEvent.y);
            break;
        }

        // run animation
        x++;
        wclear(win);
        wrefresh(win);

        mvwin(win, 1, x);
        wprintw(win, "o");
        wrefresh(win); // move o to x++
    }

    nodelay(stdscr, false);
    getch();

    endwin();
    return 0;
}
