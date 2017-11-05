#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int fd_src,fd_des,len;
	char buf[4096];
	if(argc!=3){
		printf("need two argu: src des\n");
		exit(1);
	}
	fd_src=open(argv[1],O_RDONLY);
	if(fd_src<0){
		printf("file not exit\n");
		exit(1);
	}
	umask(0);
	fd_des=open(argv[2],O_CREAT | O_EXCL | O_WRONLY,0777);
	if(fd_des<0){
		printf("file not exit\n");
		exit(1);
	}
	len=read(fd_src,buf,sizeof(buf));
	
	printf("read %d\n",len);
	write(fd_des,buf,len);
	

	close(fd_src);
	close(fd_des);
	return 0;
}