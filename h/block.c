

int main(int argc, char const *argv[])
{
	int fd,len;
	char buf[1024];
	len = read(STDIN_FILENO,buf,sizeof(buf));
	write(STDOUT_FILENO,buf,len);
	return 0;
}