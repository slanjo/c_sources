#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h> //required for getaddrinfo

void error(char *msg);
int open_socket(char *host, char *port);
int say(int socket, char *s);


int main(int argc, char *argv[]){
    int sockfd;
    sockfd = open_socket("en.wikipedia.org","443");
    char buf[255];
    sprintf(buf,"GET /wiki/%s http/1.1\r\n", argv[1]);
    say(sockfd, buf);
    say(sockfd, "Host: en.wikipedia.org\r\n\r\n");
    char rec[256];
    int bytesRcvd = recv(sockfd, rec, 255, 0);
    while (bytesRcvd){
        if (bytesRcvd == -1) 
            error("Can't read from server");
        rec[bytesRcvd] = '\0';
        printf("%s", rec); 
        bytesRcvd = recv(sockfd, rec, 255, 0);
    }
    close(sockfd);
    return 0;
}
void error(char *msg){
    fprintf(stderr, "%s: %s\n", msg,strerror(errno));
    exit(1);
}
int open_socket(char *host, char *port){
    struct addrinfo *res;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(host, port, &hints, &res) == -1)
        error("Can't resolve the address");
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1)
        error("Can't open socket");
    int conn = connect(sockfd, res->ai_addr, res->ai_addrlen);
    freeaddrinfo(res);
    if (conn == -1)
        error("Can't open socket");
    return sockfd;
}
int say(int socket, char *s){
    int result = send(socket, s, strlen(s), 0);
    if (result == -1)
        fprintf(stderr, "%s: %s\n", "Error talking to the server",
                strerror(errno));
    return result;
}
