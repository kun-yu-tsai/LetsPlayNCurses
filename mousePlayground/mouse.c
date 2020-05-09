#include <ncurses.h>

/*
    MEVENT
    typedef struct
    {
        short id;         // ID to distinguish multiple devices 
        int x, y, z;      // event coordinates 
        mmask_t bstate;   // button state bits 
    }    
*/
int main(int argc, char const *argv[])
{
    initscr();
    noecho();

    keypad(stdscr, true); // enable catching all "function keys".
    // function key: under the hood, it actually consists of a sequence of "Multiple character keys".
    // e.g: KEY_UP is a sequence of "27, 91, 65", which in ASCII represents "Escape, [, A"
    
    mousemask(ALL_MOUSE_EVENTS, NULL); 
    // enable catching all mouse events, consisting of longer sequence of ch keys.

    while (1)
    {
        int ch = getch(); // now we can get mouse event by getch

        MEVENT mouseEvent;

        if (ch == KEY_MOUSE)
        {
            int ret = getmouse(&mouseEvent);
            if (ret == OK)
            {
                if (mouseEvent.bstate & BUTTON1_CLICKED)
                {
                    printw("Mouse left click on x = %d, y = %d\n", mouseEvent.x, mouseEvent.y);
                    refresh();
                }
            }
            // else
            // {
            //     printw("Mouse catch failed");
            // }
        }
        // else
        // {
        //     printw("Catch [%c], [%d]\n", ch, ch);
        // }
    }

    endwin();
    return 0;
}
