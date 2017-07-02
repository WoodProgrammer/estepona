#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/mman.h>

static void  usageError(const char *progName){

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               fprintf(stderr,"USAGE %s",progName);
     exit(1);
}


    #define NUMINTS  (1000)
#define FILESIZE (NUMINTS * sizeof(int))


int main(int argc,char **argv){


  int flags,opt,fd;
  mode_t perms;
  size_t size;



  struct stat fileStat;
  int *map;
  int file;

  file = open("testfile2.txt",O_RDONLY);
  map = mmap(0, FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
  for(int i=0;i<=10;i++){
    map[i] = 2*i;
  }

//  if(file  == -1){
  //  return 1;
  //}

  fstat(file,&fileStat);
  printf("File Size : %d  bytes\n",fileStat.st_size );


}
