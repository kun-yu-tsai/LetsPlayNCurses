#include <ncurses.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    initscr(); // generate stdscr window

    int height, width, x, y = 0;
    height = 10;
    width = 20;
    x = 10;
    y = 10;

    // deploy a window on stdscr window.

    // apply box-border.
    box(stdscr, 0, 0);
    refresh(); // render stdscr window to the physical terminal. 
    // wrefresh(stdscr); // same as above.

    WINDOW *window = newwin(height, width, y, x); // the window is not rendered yet. It's been created in the memory.
    box(window, 0, 0); // config the window

    wprintw(window, "hello");
    wrefresh(window); // here, we "print/render" the window to the actual physical terminal.

    sleep(1);
    // wrefresh(window);

    // wgetch(window);
    // getch();

    endwin();

    return 0;
}
