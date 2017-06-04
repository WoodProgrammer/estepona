#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <netinet/in.h>


#define PORT 8080

int main(){
char str[1000];

int socketfd,newfd;
struct sockaddr_in sock_data;
struct sockaddr_in clientAddr;
int received_data,sent_data;
sock_data.sin_family=AF_INET;
sock_data.sin_port=htons(PORT);
sock_data.sin_addr.s_addr = INADDR_ANY;

socklen_t structSize;

socketfd  = socket(AF_INET,SOCK_STREAM,0);

if (socketfd == -1){
  perror("sockett");
}

bind(socketfd,(struct sockaddr * )&sock_data,sizeof(struct sockaddr));
connect(socketfd,(struct sockaddr * )&sock_data,sizeof(struct sockaddr));
int struct_size = sizeof(clientAddr);

while (1){

  listen(socketfd,20);

  structSize = sizeof(clientAddr);
  newfd = accept(socketfd, (struct sockaddr *)&clientAddr, &structSize);

  received_data = recv(newfd,&str,999,0);
  printf("%d bit gave:\t%s\n", received_data, str);
  char *data_to_send = "akjnlakşdkadiaşdnonıpowlqşdnqlşdqwidq";
  for(int i=0;i<=100;i++){
    sent_data = send(newfd,data_to_send , strlen(data_to_send), 0);
  }
  printf("%d bit data sent \t \n",sent_data );
}

}
