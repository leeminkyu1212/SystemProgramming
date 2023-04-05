#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int fd= open("./test2.txt", O_WRONLY|O_TRUNC,0664);
	if(fd<0){
		printf("[%s ::%d] FILE OPEN ERROR\n",__FILE__,__LINE__);

		exit(1);
	}
	char* buf={"thisisminkyulee\n"};
	write(fd,buf,strlen(buf));
	close(fd);

	return 0;

}

