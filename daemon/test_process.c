#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>


int main(){
  pid_t pid;
  pid = fork();
  if(pid == 0 ){
    printf("Child\n %d",getppid() );
  }
  else{
    printf("Parrent prosess \n %d ",getpid());
  }
}
