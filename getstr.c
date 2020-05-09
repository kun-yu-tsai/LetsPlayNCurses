#include <ncurses.h>

int main(int argc, char const *argv[])
{
    initscr();
    refresh();

    WINDOW * win = newwin(10,20, 5, 5);
    box(win, 0, 0);
    wrefresh(win);

    char wStr[30];
    char str[30];

    wmove(win, 1,1);
    wgetstr(win, wStr);
    mvwprintw(win, 2, 1, "Subwindow, you typed %s", wStr);
    wrefresh(win);

    getstr(str);
    printw("Def win, you typed %s", str);
    refresh();

    getch();

    endwin();
    return 0;
}
