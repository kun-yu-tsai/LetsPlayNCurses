#include <ncurses.h>
#include <unistd.h>

int main()
{
    initscr(); 
    // refresh(); // draw the window on screen (default window.)

    WINDOW *window = newwin(10, 30, 10, 10);
    // box(window, 0, 0);
    box(window, 'g', 'a');
    wborder(window,
            'a', 'b', 'c', 'd',
            'e', 'f', 'g', 'h');
    mvwprintw(window, 1, 2, "This is Ming's box");
    wrefresh(window);

    sleep(10);
    // getch();

    endwin();

    return 0;
}