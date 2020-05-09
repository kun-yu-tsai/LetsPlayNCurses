#include <ncurses.h>

int main(int argc, char const *argv[])
{
    initscr();
    
    addstr("12345");

    getch();

    move(0,1);
    clrtoeol();

    getch();

    endwin();
    return 0;
}
