#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int fd[2];
	char str[1024]="hello zhuming";
	char buf[1024];
	pid_t pid;
	int len;
	if(pipe(fd)<0){
		perror("pipe");
		exit(1);
	}
	pid=fork();
	if(pid>0){
		close(fd[0]);
		sleep(2);
		write(fd[1],str,strlen(str));
		wait(NULL);
	}else if(pid==0){
		close(fd[1]);
		len=read(fd[0],buf,sizeof(buf));
		write(STDOUT_FILENO,buf,len);
	}else{
		perror("fork");
		exit(1);
	}
	return 0;
}