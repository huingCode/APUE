#include <stdio.h>
int main(int argc, char const *argv[])
{
	int ch;
	while((ch=getchar())!=EOF)
		putchar(toupper(ch));
	return 0;
}