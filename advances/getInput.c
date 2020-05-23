#include <ncurses.h>

int main(int argc, char const *argv[])
{
    initscr();
    // noecho();
    nocbreak(); // we need to press "enter" to submit the input.
    // if it's cbreak, each character is submitted directly.

    // raw();
    // keypad(stdscr, true);

    int ch;
    while (1 && ch != 'c')
    {
        ch = getch();
        printw("[%d], [%c]\n", ch, ch);
    }

    endwin();
    return 0;
}
