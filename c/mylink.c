#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	if(link(argv[1],argv[2])<0)
		perror("link");
	return 0;
}