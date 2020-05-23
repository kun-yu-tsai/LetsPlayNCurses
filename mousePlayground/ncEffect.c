#include "ncEffect.h"

#include <unistd.h>

void blinkText(WINDOW* win, int y, int x, char* text, int blinkNum){
    while(blinkNum > 0 ){
        wattron(win, A_REVERSE);
        wattron(win, A_BOLD);
        mvwprintw(win, y, x, text);
        wrefresh(win);
        // sleep(1);
        usleep(100000); // 0.1sec = 100 ms = 100,000us

        wattroff(win, A_REVERSE);
        wattroff(win, A_BOLD);
        mvwprintw(win, y, x, text);
        wrefresh(win);
        // sleep(1);
        usleep(100000);

        blinkNum--;
    }
}