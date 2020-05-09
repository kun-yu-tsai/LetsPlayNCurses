#include "ncComponent.h"

WINDOW* createMenu(int height, int width, int y, int x, char *menuOptions[], int optionNum){
    WINDOW *menu = newwin(height, width, y, x);
    box(menu, 0, 0);

    for (int i = 0; i < optionNum; i++)
    {
        mvwprintw(menu, 1 + i, 2, menuOptions[i]);
    }

    wrefresh(menu);
    return menu;
}