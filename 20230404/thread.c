#include <stdio.h>
#include <unistd.h>

void abc(){
  while(1){
    printf("ABC\n");
    sleep(1);
  }
}

void bts(){
  while(1){
    printf("BTS\n");
    sleep(1);
  }
}

int main(){
  abc();
  bts();
}