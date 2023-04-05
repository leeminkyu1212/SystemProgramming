#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void func1(int num)
{
  printf("\n[Button Clicked]\n");
}
void func2(int num)
{
  system("clear");
  printf("\n[RESET]\n");
}
void func3(int num)
{
  printf("\nbye\n");
  exit(0);
}
int main()
{
  setbuf(stdout, NULL);
  signal(SIGUSR1, func1);
  signal(SIGUSR2, func2);
  signal(SIGTERM, func3);
  while (1)
  {
    for (char c = 'A'; c <= 'Z'; c++)
    {
      printf("%c", c);
      usleep(100 * 1000);
    }
    printf("\n");
    for (char c = 'Z'; c >= 'A'; c--)
    {
      printf("%c", c);
      usleep(100 * 1000);
    }
    printf("\n");

  }
  return 0;
}