#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(){
  struct stat * metadata;
  stat("testFile.txt",metadata);
  printf("%ld",metadata->st_size);
}
