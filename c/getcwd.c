#include "apue.h"

int main(int argc, char const *argv[])
{
	char *ptr;
	size_t size;
	if(chdir("/usr/spool/uucppublic")<0)
		printf("chdir failed\n");
	ptr=path_alloc(&size);
	if(getcwd(ptr,size)==NULL)
		printf("getcwd failed\n");
	printf("cwd=%s\n",ptr);
	exit(0);
}