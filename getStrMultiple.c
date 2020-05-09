#include <ncurses.h>

void scanMulti();
void getStrMulti();
int main(int argc, char const *argv[])
{
    initscr();
    scanMulti();
    endwin();
    return 0;
}

void getStrMulti(){
    char str[20];
    timeout(1000);
    int ret = 0;
    move(0,0);
    ret = getstr(str);
    move(0,0);
    ret = getstr(str);
    move(0,0);
    ret = getstr(str);
}

void scanMulti(){
    char str[20];
    timeout(1000);
    int ret = 0;
    // move(0,0);
    scanw("%s",str);
    // move(0,0);
    scanw("%s",str);
    // move(0,0);
    scanw("%s",str);
}