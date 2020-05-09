#include <ncurses.h>
#include <unistd.h>

#define CHOICES_NUM 4
#define TEXT_Y_OFFSET_IN_WINDOW 1
#define TEXT_X_OFFSET_IN_WINDOW 2

void renderStartMenu();

int main(int argc, char const *argv[])
{
    initscr();
    refresh();

    noecho();
    curs_set(0); // disable cursor

    renderStartMenu();

    endwin();
    return 0;
}

void renderStartMenu()
{
    WINDOW *menu = newwin(6, 50, 10, 10);
    box(menu, 0, 0);

    keypad(menu, true);

    char choices[CHOICES_NUM][20] = {
        "C programming",
        "NCurses programming",
        "Arduino board",
        "Exit"};

    int currentChoice = 0;

    while (1)
    {
        for (int index = 0; index < CHOICES_NUM; index++)
        {
            // we'll have to turn on A_REVERSE to hightlight "currentChoice".
            // If it's not currentChoice, A_REVERSE will be off.
            if (index == currentChoice)
            {
                wattron(menu, A_REVERSE);
            }

            // this is move to specific position and do print.
            mvwprintw(
                menu,
                index + TEXT_Y_OFFSET_IN_WINDOW,
                TEXT_X_OFFSET_IN_WINDOW,
                choices[index]);

            wattroff(menu, A_REVERSE);
        }

        wrefresh(menu);

        int userInput = wgetch(menu);

        switch (userInput)
        {
        case KEY_UP:
            currentChoice--;
            break;
        case KEY_DOWN:
            currentChoice++;
            break;
        default:
            break;
        }

        // makes the up and down can loop the whole choice list
        if (currentChoice == -1)
            currentChoice = CHOICES_NUM - 1;
        if (currentChoice == CHOICES_NUM)
            currentChoice = 0; // jump back to 0.

        if (userInput == 10) // press enter
        {
            mvprintw(5, 10, "You picked %s", choices[currentChoice]);
            refresh();

            if (currentChoice == (CHOICES_NUM - 1)) // picked exit
            {
                delwin(menu); // delete menu window to free memory.
                return;
            }
        }
    }
}
