#include <ncurses.h>

int main(int argc, char const *argv[])
{
    initscr();

    cbreak();

    wtimeout(stdscr, 2000); // 2 secs

    int timeLeft = 5; // wait for 5 secs

    int ch = ERR; // init ch ERR in the very beginning.

    while (timeLeft > 0) // if there's still time, we'll keep doing
    {
        if (ch == ERR)
        {
            if (timeLeft == 0)
            {
                mvprintw(0, 0, "You failed to answer!\n");
                break;
            }
            else
            {
                // prompt user how many time left
                mvprintw(0, 0, "You still have %d secs to answer. \n", timeLeft);
                timeLeft--;
            }
        }
        else
        {
            mvprintw(2, 1, "You selected %c\n", ch);
            break;
        }

        ch = wgetch(stdscr); // start to wait for 1000 ms
        // ch = ERR
    }

    // nodelay(stdscr, true); // this represent timeout time is 0 sec.
    nodelay(stdscr, false); // set timeout time to unlimited.
    getch();

    endwin();
    return 0;
}
