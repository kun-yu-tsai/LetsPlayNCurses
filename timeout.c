#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define ANSWER "Donald Trump"

int main(int argc, char const *argv[])
{
    initscr();
    refresh();

    int ret = ERR;
    char answer[20];

    WINDOW *win = newwin(20, 100, 5, 5);
    box(win, 0, 0);

    wrefresh(win);
    wtimeout(win, 1000);

    wmove(win, 1, 1);
    wprintw(win, "Question: who is the president of the U.S?");

    int winY = 3, winX = 1;

    while (ret == ERR)
    {
        // draw picture.
        mvprintw(1, 1, " o  \n /#\\  \n _|_ ");
        refresh();

        // move cursor to previous location
        wmove(win, winY - 1, winX);
        wrefresh(win);
        ret = wgetstr(win, answer);
        
        // timeout, remember the current cursor location.
        getyx(win, winY, winX);
    }

    if (strcmp(answer, ANSWER) == 0)
    {
        mvprintw(4, 1, "Right on. Congratulation!");
    }
    else
    {
        mvprintw(4, 1, "Wrong~ The answer is %s", ANSWER);
    }

    refresh();

    getch();

    endwin();
    return 0;
}
