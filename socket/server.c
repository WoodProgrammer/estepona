#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>

int main(int argc, char const *argv[]) {
  int socket_test , new_socket,port_number,client_len,n;
  struct sockaddr_in serv_addr, cli_addr;
  socket_test  = socket(AF_INET,SOCK_STREAM,0);
  if(socket_test<0){
    printf("Some Errors on the hole .. \n" );
  }
  return 0;
}
