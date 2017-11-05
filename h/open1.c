#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int fd;
	char buf[]="hello";
	if(argc<2){
		printf("./app filename\n");
		exit(1);
	}
	fd=open(argv[1],O_RDWR);
	printf("fd=%d\n",fd);
	write(fd,buf,sizeof(buf));
	close(fd);
	return 0;
}