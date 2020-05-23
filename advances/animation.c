#include <ncurses.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    initscr();
    curs_set(0);

    const char textGraph[2][20] = {"  o  \n /#\\  \n _|_ ", " \\o/ \n  #  \n_/ \\_ "};

    int winY = 5;
    int winX = 0;

    WINDOW *animWin = newwin(10, 20, winY, winX);
    int index = 0;

    while (1)
    {
        // completely clear the window
        wclear(animWin);
        wrefresh(animWin);

        // move win. this one is crucial
        mvwin(animWin, winY, winX);

        // redraw content on the new-positioned window
        mvwprintw(animWin, 0, 0, textGraph[index]);
        wrefresh(animWin);

        winX = winX + 3; // move x
        winY = winY + 1; // move y

        index = (index + 1) % 2;
        usleep(200000);
    }

    endwin();
    return 0;
}