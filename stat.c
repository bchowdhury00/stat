#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int main(){
  struct stat * metadata;
  stat("testFile.txt",metadata);
  long size = metadata->st_size;
  int counter = 0;
  while ((size % 1024) > 1024){
    size /= 1024;
    counter++;
  }
  char * unit = "B";
  if (counter == 1)
    unit = "KB";
  if (counter == 2)
    unit = "MB";
  if (counter ==3)
    unit = "GB";
  printf("%ld %s\n",size,unit);
  printf("%o\n",metadata->st_mode);
  printf("Time last accessed : %s\n",ctime(&(metadata->st_atime)));
  
}
