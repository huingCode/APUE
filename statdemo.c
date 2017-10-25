#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  struct stat st; 
  int r = stat("test.txt", &st);
  if (r) {
    perror("stat");
    return -1; 
  }

  printf("st_dev = %lld\n", st.st_dev);
  printf("st_ino = %ld\n", st.st_ino);
  printf("st_mode = %d\n", st.st_mode);
  printf("st_nlink = %d\n", st.st_nlink);
  printf("st_uid = %d\n", st.st_uid);
  printf("st_gid = %d\n", st.st_gid);
  printf("st_size = %ld\n", st.st_size);

  printf("st_atime = %ld\n", st.st_atime);
  printf("st_mtime = %ld\n", st.st_mtime);
  printf("st_ctime = %ld\n", st.st_ctime);
  return 0;
}