#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int fd;
	char buf[4096];
	if(fd=open("hello.txt",O_RDONLY)<0)
		perror("open");
	printf("fd=%d\n",fd);
	read(fd,buf,4096);
	printf("%s\n",buf);

	return 0;
}