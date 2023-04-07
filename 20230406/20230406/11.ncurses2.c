#include <ncurses.h>
#include <unistd.h>

int main(){
  initscr();

  printw("HELLO");  
  refresh();
  sleep(1);

  printw(" NEXT");  
  refresh();
  sleep(1);

  printw(" TARGET\n");  
  printw("is\n");  
  refresh();
  sleep(1);

  printw("gogo\nbye");  
  refresh();
  sleep(1);
  
  endwin();
  return 0;
}