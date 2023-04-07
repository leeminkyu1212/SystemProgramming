#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

char vect[4][21] = {

    "ABCDEFGHIJKLMNOPQRST",
    "HIFAKERHIFAKERHIFAKE",
    "BBQBBQBBQBBQBBQBBQBB",
    "MACMACMACMACMACMACMA",
};

void *abc(void *s)
{
  char *s1 = (char *)s;
  for (int i = 0; i < 20; i++)
  {
    s1[i] += 3;
  }
}

int main()
{

  pthread_t t[4];

  for (int i = 0; i < 4; i++)
  {
    pthread_create(&t[i], NULL, abc, &vect[i][0]);
  }

  for (int i = 0; i < 4; i++)
  {
    pthread_join(t[i], NULL);
  }
  for (int i = 0; i < 4; i++)
  {
    printf("%s\n", vect[i]);
  }
  return 0;
}