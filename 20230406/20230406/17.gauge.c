#include <ncurses.h>
#include <unistd.h>


int main(){
  initscr();

  while(1){
    for(int y=0;y<30;y++){
      clear;
      for(int x=0;x<=y;x++){
        printw("*");
      }
      printw("\n");
      refresh();
      usleep(30*1000);
    }
  }
  getch();
  endwin();
}