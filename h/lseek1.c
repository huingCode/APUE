//测试lseek一个有内容的文件
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int fd,len;
	if((fd=open("./abc",O_RDWR))<0){
		perror("open abc");
	}
	printf("lseek=%d",lseek(fd,0x1000,SEEK_SET));
	close(fd);
	return 0;
}