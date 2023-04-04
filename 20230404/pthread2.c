#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *dd1()
{
  while (1)
  {
    for (char c = 'A'; c <= 'C'; c++)
    {
      printf("[DD1] %c\n", c);
      usleep(300 * 1000);
    }
  }
  return 0;
}

void *dd2()
{
  while (1)
  {
    for (int i = 0; i <= 5; i++)
    {
      printf("[DD2] %d\n",i);
      usleep(200 * 1000);
    }
  }
  return 0;
}

void *dd3()
{
  while (1)
  {
    for (char c = 'A'; c <= 'Z'; c++)
    {
      printf("[DD3] %c\n", c);
      usleep(300 * 1000);
    }
  }
  return 0;
}

int main()
{
  pthread_t t1, t2, t3;

  pthread_create(&t1, NULL, dd1, NULL);
  pthread_create(&t2, NULL, dd2, NULL);
  pthread_create(&t3, NULL, dd3, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
}