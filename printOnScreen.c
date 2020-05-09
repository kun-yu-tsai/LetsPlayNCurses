#include <ncurses.h>
#include <unistd.h>

int main()
{
    initscr(); /* Initialise default window "stdscr", and call refresh on it. */
    move(10, 50); // y, x

    printw("Hello Ming!");
    // wprintw(stdscr, "Hello Ming!");

    refresh(); // render "the window" to the physical terminal.
    
    // noecho();
    // int num = getch(); /* Wait for user input */
    sleep(1);

    // move(0, 0);
    // printw("%d", num);
    // refresh();

    endwin(); /* Clear the screen. Render the orignial state of terminal back. */

    return 0;
}