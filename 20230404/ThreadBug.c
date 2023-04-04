#include <stdio.h>
#include <pthread.h>

pthread_t tid[4];
int cnt;
void *run(void *arg)
{
  for (int i = 0; i < 10000; i++)
    cnt++;
}

int main()
{
  int id[37];
  for (int i = 0; i < 4; i++)
  {
    pthread_create(&tid[i], NULL, run, &i);
  }
  for (int i = 0; i < 4; i++)
    pthread_join(tid[i], NULL);

  printf("%d\n",cnt);
}