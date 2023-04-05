#include <ncurses.h>

int main(){

  initscr();

  printw("helloworld\n");
  refresh();
  getch();

  endwin();
  return 0;

}