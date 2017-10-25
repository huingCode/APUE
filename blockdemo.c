#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char buf[10];
	int len;
	while(1){
		len = read(STDIN_FILENO,buf,10);
		write(STDOUT_FILENO,buf,len);
	}
	return 0;
}