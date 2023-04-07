#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    initscr();
    srand(time(NULL));

    while(1){
        int y=rand()%30;
        int x=rand()%30;

        move(y,x);

        printw("*");

        refresh();
        usleep(1000);
    }

    endwin();

    return 0;

}