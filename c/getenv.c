#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("PATH=%s\n",getenv("PATH"));
	setenv("PATH","hello",1);
	printf("PATH=%s\n",getenv("PATH"));
	return 0;
}