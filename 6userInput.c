#include <ncurses.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    initscr();

    keypad(stdscr, true);
    
    int c = getch();

    if(c == KEY_UP){
        printw("You pressed UP!");
    }

    refresh();
    sleep(1);

    endwin();
    return 0;
}
