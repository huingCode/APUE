#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int fd=open("./hello",O_CREAT|O_RDWR);
	printf("fd=%d\n",fd);
	return 0;
}