/// 연산속도 측정하기
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int loop = 100000000;
int main()
{

  clock_t start, end;
  start = clock();
  int a = 1;
  for (int i = 0; i < loop; i++)
  {
    a++;
  }
  end = clock();
  printf("%ld\n", end - start);

  start = clock();
  a = 1;
  for (int i = 0; i < loop; i++)
  {
    a /= 11;
  }
  end = clock();
  printf("%ld\n", end - start);

  start = clock();
  a = 1;
  for (int i = 0; i < loop; i++)
  {
    a = a << 11;
  }
  end = clock();
  printf("%ld\n", end - start);
  return 0;
}