#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	int fd[2];
	char str[1024]="hello zhuming";
	char buf[1024];
	pid_t pid;

	if(pipe(fd)<0){
		perror("pipe");
		exit(1);
	}
	pid=fork();
	if(pid>0){
		close(fd[0]);
		sleep(5);
		write(fd[1],str,strlen(str));
		wait(NULL);
	}
	else if(pid==0){
		int len,flag;
		close(fd[1]);
		flag=fcntl(fd[0],F_GETFL);
		flag|=O_NONBLOCK;
		fcntl(fd[0],F_SETFL,flag);
tryagain:
		len=read(fd[0],buf,sizeof(buf));
		if(len==-1){
			if(errno==EAGAIN){
				write(STDOUT_FILENO,"try again\n",10);
				sleep(1);
				goto tryagain;
			}else{
				perror("read");
				exit(1);
			}
		}
		write(STDOUT_FILENO,buf,len);
	}else{
		perror("fork");
		exit(1);
	}
	return 0;
}