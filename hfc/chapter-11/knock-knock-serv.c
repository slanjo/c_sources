//this is a server that can receive input from client
//it forks connections for differnt clients
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#define SIN_PORT 30000
#include "server_headers.h"

int main(int argc, char *argv[]){
    if(catch_signal(SIGINT,handle_shutdown) == -1)
        error("Can't set the interrupt handler");
    int sockfd = open_listener_socket();
    printf("Listerner Socekt: %i\n", sockfd);
    bind_to_port(sockfd, SIN_PORT);
    if (listen(sockfd, 20) == -1)
      error("Can't listen!!!");
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    puts("waiting for connection");
    char buf[255];
    while(1)
    {
        int clnt_socfd = accept (sockfd, (struct sockaddr *)&client_addr,
                &address_size);
        if (clnt_socfd == -1)
            error("Can't open second socket/accept() call failure");
        if (!fork())
        {
            close(sockfd);
            if (say(clnt_socfd,"<Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n>")
                != -1)
            {
                read_in(clnt_socfd, buf, sizeof(buf));
                if(strncasecmp("Who's there?", buf, 12))
                   say(clnt_socfd, "You should say 'Who's there?'!");
                else
                {
                   if (say(clnt_socfd, "Oscar\r\n> ") != -1)
                   {
                         read_in(clnt_socfd, buf, sizeof(buf));
                         if(strncasecmp("Oscar who?", buf, 10))
                             say(clnt_socfd,"You should say 'Oscar who?'!\r\n");
                         else
                             say(clnt_socfd, "Oscar silly question, you get a silly answer\r\n");
                   }
                }
            }
            close(clnt_socfd);
            exit(0);
        }
        close(clnt_socfd);
    }        
return 0;
}
int catch_signal(int sig,void (*handle_shutdown)(int)){
    struct sigaction action;
    action.sa_handler = handle_shutdown;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);

}
int read_in(int socket, char *buf, int len){
    char *s = buf;
    int slen = len;
    int c = recv(socket, s, slen, 0);
    while ((c > 0) && (s[c - 1] != '\n')){
        s += c; slen -= c;
        c = recv(socket, s, slen, 0);
    }
    if (c < 0)
        buf[0] = '\0';
    else
        s[c - 1] = '\0';
    return len - slen;
}
void bind_to_port(int socket, int port){
    struct sockaddr_in name;
    name.sin_family = AF_INET;
    name.sin_port = (in_port_t)htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    int reuse = 1;
    if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char *) &reuse, sizeof(int)) == -1)
        error("Can't set the reuse option on the socket");
    int c = (bind(socket, (struct sockaddr *) &name, sizeof(name)) == -1);
    if (c == -1)
        error("Can't bind the port");
}
int open_listener_socket(){
    int sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd == -1){
        error("Can't open socket");
    };
    return sockfd;
}
int say(int socket, char *s){
    int result = send(socket, s, strlen(s), 0);
    if (result == -1)
        fprintf(stderr, "%s: %s\n", "Error talking to the client",
                strerror(errno));
    return result;
}
void error(char *msg){
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}
void handle_shutdown(int sig){
    if (listener_d)
        close(listener_d);
    fprintf(stderr, "Bye!\n");
    exit(0);
}
