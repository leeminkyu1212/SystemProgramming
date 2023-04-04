#include <stdio.h>
#include <pthread.h>

pthread_t tid[4];

void *abc(void *arg)
{
  int a = *(int *)arg;
  if(a==1){
    printf("ABC\n");
  }
  else if(a==2){
    printf("MININ\n");
  }
  else if(a==3){
    printf("COCO\n");
  }
    else if(a==4){
    printf("KFCKFC\n");
  }

}

int main()
{
  int id[5];
  for (int i = 1; i <= 4; i++)
  {
    id[i] = i;
    pthread_create(&tid[i], NULL, abc, &id[i]);
  }
  for (int i = 0; i < 4; i++)
    pthread_join(tid[i], NULL);
  return 0;
}