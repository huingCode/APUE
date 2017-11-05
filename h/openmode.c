#include "apue.h"
#include <fcntl.h>
int main(int argc, char const *argv[])
{
	printf("O_RDONLY=%d,O_WRDONLY=%d,O_RDWR=%d\n",O_RDONLY,O_WRONLY,O_RDWR);
	return 0;
}