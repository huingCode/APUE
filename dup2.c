#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	int fd1=open("log_",O_RDWR | O_CREAT | O_EXCL);
	char string[256]={0};
	sprintf(string,"fd=%d",fd1);
	write(STDOUT_FILENO,string,256);
	close(STDOUT_FILENO);
	dup2(fd1,STDOUT_FILENO);
//	close(fd1);
	write(STDOUT_FILENO,"stdout -z",10);
	return 0;
}
