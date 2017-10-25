#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>

void traversal(DIR* dir){
	struct dirent* de=NULL;
	while((de=readdir(dir))!=NULL){
		printf("%ld\t0x%02x\t%ld\t%s\n",de->d_ino,de_type,de->d_off,de->d_name);
	}
}

int main(int argc, char const *argv[])
{
	DIR *dp=opendir(argv[1]);
	if(!dp){
		printf("opendir");
		return -1;
	}
	traversal(dp);
	closedir(dp);
}