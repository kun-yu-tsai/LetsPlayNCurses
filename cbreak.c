#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    initscr();
    // noecho();
    nocbreak();

    int c = getch();
    printw("%c", c);
    
    getch();
    getch();
    
    endwin();
}