#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void gogo(){
        printf("System error\n");
        exit(1);
}

int main()
{
        signal(SIGALRM,gogo);

        printf("3 second\n");
        alarm(3);
        printf("wait...\n");

        while(1){
                sleep(3);
                exit();
        }
        return 0;
}