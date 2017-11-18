#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t pid;

	pid=fork();
	if(pid==0){
		execl("/home/c/apue/app",NULL);
	}else if(pid>0){
		
	}else{
		perror("fork");
		exit(1);
	}
	return 0;
}