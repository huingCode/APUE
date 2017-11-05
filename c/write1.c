#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int fd;
	char buf[1024]="world";
	if(argc!=2){
		printf("file 1 arg:usage\n");
		exit(1);
	}
	fd=open(argv[1],O_RDWR | O_APPEND);
	if(fd<0){
		perror("open");
		exit(1);
	}
	write(fd,buf,strlen(buf));
	close(fd);
	return 0;
}