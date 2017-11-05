#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int fd=open("abc",O_RDWR);
	if(fd<0){
		perror("open abc");
		exit(-1);
	}

	lseek(fd,0x1000,SEEK_SET);
	write(fd,"a",1);
	close(fd);

	return 0;
}