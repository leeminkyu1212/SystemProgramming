#include <unistd.h>
#include <ncurses.h>
int main(){
  initscr();
  move(10,30);

  printw("GAME OVER\n");
  refresh();

  sleep(2);
  endwin();
  return 0;
}