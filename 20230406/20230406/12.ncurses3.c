#include <ncurses.h>
#include <unistd.h>

int main()
{
  initscr();

  for (char c = 'A'; c <= 'Z'; c++)
  {
    printw("%c", c);
    refresh();
    usleep(100*1000);
  }
  endwin();
  return 0;
}