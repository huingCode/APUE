#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	pid=fork();
	if(pid<0){
		perror("fork fail");
		exit(1);
	}
	if(pid==0){
		int i;
		for(i=3;i>0;i--){
			printf("This is the child");
			sleep(1);
		}
		exit(3);
	}else{
		int stat_val;
		waitpid(pid,&stat_val,0);
		if(WIFEXITED(stat_val))
			printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
		else if(WIFSIGNALED(stat_val))
			printf("Child terminated abnomally,signal %d\n",WIERMSIG(stat_val));

	}
	
	return 0;
}