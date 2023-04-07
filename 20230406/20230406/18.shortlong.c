#include <ncurses.h>
#include <unistd.h>


int main(){
  initscr();

  while(1){
    for(int y=0;y<30;y++){
      clear();
      for(int x=0;x<=y;x++){
        printw("#");
      }
      refresh();
      usleep(30*1000);
    }
    for(int y=30;y>=0;y--){
      clear();
      for(int x=0;x<=y;x++){
        printw("#");
      }
      refresh();
      usleep(30*1000);
    }
  }
  getch();
  endwin();
}