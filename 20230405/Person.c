#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>


int main(int argc, char* argv[]){
  if(argc !=2){
    printf("error\n");
    return 0;
  }

  int pid=atoi(argv[1]);
  int cmd;

  while(1){


    printf("input>> ");
    scanf("%d",&cmd);

    if(cmd==1) kill(pid,SIGUSR1);
    if(cmd==2) kill(pid,SIGUSR2);
    if(cmd==3) kill(pid,SIGTERM);

  }
  return 0;
}