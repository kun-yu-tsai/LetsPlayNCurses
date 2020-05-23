#include <ncurses.h>

int main(int argc, char const *argv[])
{
    initscr();
    noecho();

    // set timeout for stdscr
    wtimeout(stdscr, 1000); // unit: milliseconds

    char ch = getch(); // I will wait for 1000 ms for user input. If user didn't input in 1000ms, I will respond an ERR.
    // 0 ms
    // 500ms
    // 1000ms
    // set ch = ERR
    // keep executing next line of code

    // if timeout time runs out, we receive ERR in ch
    if( ch == ERR){
        printw("Error");
    }
    else{
        printw("You typed %c", ch);
    }
    
    nodelay(stdscr, false);
    getch();

    endwin();
    return 0;
}
