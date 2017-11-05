#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int fd;
	int i = 0;
	char name[1024];
	while(1){
		sprintf(name,"file%d",++i);
		fd=open(name,O_CREAT,0777);
		if(fd<0)
			break;
		printf("i=%d\n",i);
	}
	return 0;
}