#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	pid_t pid;
	pid=fork();
	if(pid>0){
		printf("I am parent\n");
		while(1);
	}else if(pid==0){
		printf("I am child\n");
		while(1); 
	}
	return 0;
}