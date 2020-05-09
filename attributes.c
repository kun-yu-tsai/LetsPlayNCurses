#include <ncurses.h>

int main(int argc, char const *argv[])
{
    initscr();
    if (!has_colors())
    {
        printw("No color mate.");
        getch();
        return -1;
    }

    // noecho();
    start_color();

    init_pair(1, COLOR_BLUE, COLOR_GREEN);
    attron(COLOR_PAIR(1));
    printw("A new color mate!");
    attroff(COLOR_PAIR(1));

    getch();

    if (can_change_color())
    {
        printw("Can change color\n");
        init_color(10, 150, 150, 500);
        init_pair(2, 10, COLOR_BLACK);
        attron(COLOR_PAIR(2));
        printw("Custom defined color!");
        attroff(COLOR_PAIR(2));
        getch();
    }
    /*
        A_NORMAL        Normal display (no highlight)
        A_STANDOUT      Best highlighting mode of the terminal.
        A_UNDERLINE     Underlining
        A_REVERSE       Reverse video
        A_BLINK         Blinking
        A_DIM           Half bright
        A_BOLD          Extra bright or bold
        A_PROTECT       Protected mode
        A_INVIS         Invisible or blank mode
        A_ALTCHARSET    Alternate character set
        A_CHARTEXT      Bit-mask to extract a character
        COLOR_PAIR(n)   Color-pair number n 
    */

    attron(A_UNDERLINE);
    printw("Hello!!");
    attroff(A_UNDERLINE);

    getch();
    endwin();
    return 0;
}
