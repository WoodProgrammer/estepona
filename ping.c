#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define PORT 5000
#define IP "127.0.0.1"
#define DESTINATION 8000

int main(int argc, char *argv[] ){
    int sockfd,counter = 0;



    struct sockaddr_in serverAddr;
    char *message = "HELLOSERVER";

    char str[1000];
    int coming_data, sending_data, structSize;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(IP);
    memset(&(serverAddr.sin_zero), '\0', 8);

    if(connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr)) == -1 ){
        perror("connect");
    }

    int num = atoi(argv[1]);
    if(num!=13){
      while(counter<= num){
        sending_data  = send(sockfd, message, strlen(message), 0);
        printf("SENT %lu bit data to %s:%d \n", strlen(message),IP,PORT );
        counter++;
      }
    }
    else{
      while(1){
        sending_data  = send(sockfd, message, strlen(message), 0);
        printf("SENT %lu bit data to %s:%d \n", strlen(message),IP,PORT );

      }
    }
  return 0;
}
