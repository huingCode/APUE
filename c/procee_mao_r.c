#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define MAPLEN 0X1000
void sys_err(char *str,int exitno){
	perror(str);
	exit(exitno);
}
int main(int argc, char const *argv[])
{
	char *mm;
	int fd;
	int i=0;
	if(argc<2){
		printf("two arg\n");
		exit(1);
	}
	fd=open(argv[1],O_RDWR );
	if(fd<0)
		sys_err("open",1);

	mm = mmap(NULL,MAPLEN,PROT_READ | PROT_WRITE, MAP_SHARED,fd,0);
	close(fd);
	if(mm==MAP_FAILED)
		sys_err("mmap",2);

	while(1){
		printf("%s\n",mm);
		sleep(1);
	}
	munmap(mm,MAPLEN);
	return 0;
}