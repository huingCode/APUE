#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 4096

int main(int argc, char const *argv[])
{
	char buf[SIZE];
	chdir("/");
	printf("%s\n",getcwd(buf,sizeof(buf)));
	return 0;
}