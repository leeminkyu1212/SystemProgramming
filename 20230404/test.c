#include <stdio.h>

int main()
{
  int x = 0;
  char t = 'A';

  void *p1 = &x;
  void *p2 = &t;

  int *p = (int *)p1;
  // printf("%d",*p); 불가능
  printf("%d", *(int *)p1); // 가능
}