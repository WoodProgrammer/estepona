#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define EXPIRE_TIME 7

char * data;

char * read_html_doc(){

	FILE * pFile;
  	long lSize;
  	char * buffer;
  	size_t result;

  	pFile = fopen ( "second.c" , "rb" );

  	fseek (pFile , 0 , SEEK_END);	
  	lSize = ftell (pFile);
  	rewind (pFile);


  	buffer = (char*) malloc (sizeof(char)*lSize);

  	result = fread (buffer,1,lSize,pFile);
  	if (result != lSize) {fputs ("OKUMA HATASI :: read_error .. ",stderr); exit (3);}
  	return buffer;
}

void cache(){
    while(1){
      data = read_html_doc();     
      sleep(EXPIRE_TIME);
     } 
}
   
   
int main(int argc , char **argv){
	
	pthread_t ph1 ; 
	pthread_create(&ph1,NULL,cache,NULL);

	while(1){
    printf("%s",data);

  }
	
    return 0;


}


 

