#include "apue.h"
#include <fcntl.h>
int main(int argc, char const *argv[])
{
	int i,fd;
	struct stat statbuf;
	struct timespec times[2];
	for(i=1;i<argc;i++){
		if(stat(argv[1],&statbuf)<0){
			printf("%s:stat error\n",argv[i]);
			continue;
		}
		if((fd=open(argv[i],O_RDWR | O_TURNC))<0){
			printf("%s:open error\n",argv[i]);
			continue;
		}
		times[0]=statbuf.st_atim;
		times[1]=statbuf.st_mtim;
		if(futimens(fd,times)<0)
			printf("%s:futimens error",argv[i]);
		close(fd);
	}
	exit(0);
}