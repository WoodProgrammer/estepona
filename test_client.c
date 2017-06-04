#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define SUNUCUPORT 8080
#define SUNUCUIP "127.0.0.1"
#define AZAMIUZUNLUK 8080

int main(){
    int sockfd;
    struct sockaddr_in serverAddr;
    char *message = "HELLO SERVER ";
    char str[1000];
    int coming_data, sending_data, structSize;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SUNUCUPORT);
    serverAddr.sin_addr.s_addr = inet_addr(SUNUCUIP);
    memset(&(serverAddr.sin_zero), '\0', 8);

    if(-1 == connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr))){
        perror("connect");
    }

    sending_data  = send(sockfd, message, strlen(message), 0);
    printf("Sent : %d\tWent: %d\n", strlen(message), sending_data);
    printf("%d bit sent:\t%s\n", strlen(message), message);

    coming_data = recv(sockfd, &str, 1000-1, 0);

    printf("%d bit received:\t%s\n", coming_data, str);

  return 0;
}
