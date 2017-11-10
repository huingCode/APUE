#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc, char const *argv[])
{
	int fd1,fd2;
	off_t len1,len2;
	struct stat st;
	fd1=open("./test",O_RDWR);
	printf("fd1=%d\n\n",fd1);
	if(fd1<0){
		perror("open fd1");
	}
	fd2=open("./test",O_RDWR);
	printf("fd2=%d\n\n",fd2);
	if(fd2<0){
		perror("open fd2");
	}
	len1=lseek(fd1,10,SEEK_SET);
	if(len1<0){
		perror("lseek fd1");
	}
	len2=lseek(fd2,10,SEEK_SET);
	if(len2<0){
		perror("lseek fd1");
	}
	printf("len1=%ld\nlen2=%ld\n",len1,len2);
	return 0;
}