#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	execlp("ls","hehe","-l",NULL);
	printf("error\n");
	return 0;
}