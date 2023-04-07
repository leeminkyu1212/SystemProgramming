#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{

  time_t current_time = time(NULL);
  struct tm *tmm = localtime(&current_time);
  char mon[7][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
  while(1){
    current_time=time(NULL);
    tmm=localtime(&current_time);

    printf("%d/%d /%s\n", tmm->tm_year,tmm->tm_mon,mon[tmm->tm_wday]);
    printf("%d : %d : %d\n",tmm->tm_hour,tmm->tm_min,tmm->tm_sec);
    sleep(1);
  }
  return 0;
}