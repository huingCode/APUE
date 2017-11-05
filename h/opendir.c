#include "apue.h"
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int fd=open("history",O_RDONLY);
	printf("fd=%d\n",fd);
	return 0;
}