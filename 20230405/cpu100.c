#include <stdio.h>
#include <pthread.h>

void *abc()
{
  while (1)
  {
  }
}

int main()
{
  pthread_t tid[4];

  for (int i = 0; i < 4; i++)
  {
    pthread_create(&tid[i], NULL, abc, NULL);
  }
  for (int i = 0; i < 4; i++)
  {
    pthread_join(tid[i], NULL);
  }
}