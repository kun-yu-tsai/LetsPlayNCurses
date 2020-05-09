#include <ncurses.h>

int main(int argc, char const *argv[])
{
    initscr();

    WINDOW * win = newwin(10,20, 5, 5);
    box(win, 0, 0);
    wrefresh(win);

    char str[20];
    wmove(win, 1,1);
    wscanw(win, "%s", str);

    printw("You typed %s", str);
    refresh();

    getch();
    
    endwin();

    return 0;
}
