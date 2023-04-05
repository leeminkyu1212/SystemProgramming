#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int fd =open("./cal.txt" ,O_RDONLY,0);

	char buf[1000]={0};

	read (fd,buf,1000);

	close(fd);

	int num= atoi(buf);

	num*=2;
	
	printf("\n==[%d]==\n" ,num);

	sprintf(buf,"%d",num);

	fd=open("./cal.txt",O_WRONLY,0);

	write(fd,buf,strlen(buf));

	close(fd);

	return 0;
}

