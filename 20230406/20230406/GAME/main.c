#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 7

char map[N][N + 1] = {
    "#######",
    "#     #",
    "#^##  #",
    "#    a#",
    "#   ###",
    "#    Y#",
    "#######"};

int ny = 1;
int nx = 1;
int hp = 100;
int my = 5;
int mx = 1;

void print()
{
  clear();
  for (int y = 0; y < N; y++)
  {
    for (int x = 0; x < N; x++)
    {
      if (y == ny && x == nx)
      {
        printw("@@");
      }
      else if (y == my && x == mx)
      {
        printw("MM");
      }
      else if(map[y][x]=='#'){
        printw("##");
      }
      else if(map[y][x]=='^'){
        printw("^^");
      }
      else if(map[y][x]=='Y'){
        printw("YY");
      }
      else if(map[y][x]=='a'){
        printw("aa");
      }
      else if(map[y][x]==' '){
        printw("  ");
      }
      else
      {
        printw("%c", map[y][x]);
      }
    }
    printw("\n");
  }
  printw("HP : %d\n", hp);
  refresh();
}

void *Move()
{
  srand(time(NULL));
  int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
  while (1)
  { 
    int ran1=rand()%4;
    int ran2=rand()%4;
    
    my += dir[ran1][0];
    mx += dir[ran2][1];
    if (map[my][mx] == '#')
    {
      my -= dir[ran1][0];
      mx -= dir[ran2][1];
    }
    usleep(200 * 1000);
  }
  return 0;
}

int main()
{
  setlocale(LC_CTYPE, "ko_KR.utf8");
  initscr();

  pthread_t mon;

  pthread_create(&mon, NULL, Move, NULL);

  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  while (1)
  {

    print();
    int ch = getch();
    if (ch == ERR)
      ch = 0;

    if (ch == KEY_LEFT)
    {
      if (map[ny][nx - 1] == '#')
        continue;

      nx--;
      if (map[ny][nx] == '^')
        hp -= 10;
      if (map[ny][nx] == 'a')
      {
        hp += 10;
        map[ny][nx] = ' ';
      }
    }

    else if (ch == KEY_DOWN)
    {
      if (map[ny + 1][nx] == '#')
        continue;

      ny++;
      if (map[ny][nx] == '^')
        hp -= 10;
      if (map[ny][nx] == 'a')
      {
        hp += 10;
        map[ny][nx] = ' ';
      }
    }
    else if (ch == KEY_UP)
    {
      if (map[ny - 1][nx] == '#')
        continue;

      ny--;
      if (map[ny][nx] == '^')
        hp -= 10;
      if (map[ny][nx] == 'a')
      {
        hp += 10;
        map[ny][nx] = ' ';
      }
    }
    else if (ch == KEY_RIGHT)
    {
      if (map[ny][nx + 1] == '#')
      {
        continue;
      }
      nx++;
      if (map[ny][nx] == '^')
        hp -= 10;
      if (map[ny][nx] == 'a')
      {
        hp += 10;
        map[ny][nx] = ' ';
      }
    }
    if ((ny==my&&nx==mx) || hp <= 0)
    {
      usleep(500 * 1000);
      clear();
      move(10, 30);
      printw("Game Over");
      refresh();

      sleep(1);
      // getch();
      endwin();
      pthread_join(mon, NULL);
      return 0;
    }
    if (map[ny][nx] == 'Y')
    {
      usleep(500 * 1000);
      clear();
      move(10, 30);
      printw("WIN %d", hp);
      refresh();

      sleep(1);
      // getch();
      endwin();
      pthread_join(mon, NULL);

      return 0;
    }
  }

  getch();
  endwin();
  pthread_join(mon, NULL);

  return 0;
}