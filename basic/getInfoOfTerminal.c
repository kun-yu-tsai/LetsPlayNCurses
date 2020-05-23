#include <ncurses.h>

int main()
{
    initscr(); // Init the default window.

    int y, x = 0;

    move(10, 10);
    getyx(stdscr, y, x);
    printw("%d, %d", y, x);
    getch();

    getmaxyx(stdscr, y, x);
    printw("%d, %d", y, x);

    mvprintw(y / 2, x / 2, "This is middle");
    getch();
    clear();

    WINDOW *win = newwin(10, 10, 10, 5);
    refresh();

    getyx(win, y, x);
    wprintw(win, "%d, %d", y, x);

    getmaxyx(win, y, x);
    wprintw(win, "%d, %d", y, x);

    wrefresh(win);

    getch();
    endwin();

    return 0;
}