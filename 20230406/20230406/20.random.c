#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
  initscr();

  while (1){

    clear();
    printw("%d\n",rand());
    printw("%d\n",rand()%5);

    refresh();
    usleep(100*1000);


  }
  endwin();
  return 0;
}