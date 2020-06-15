//this is a server that can receive input from client

#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#define SIN_PORT 30000
//if (c == -1)
//    error("Can't bind to socket");
int read_in(int socket, char *buf, int len);
void bind_to_port(int socket, int sin_port);
int open_listener_socket();
int say(int socket, char *s);
void error(char *msg);
int listener_d;
void handle_shutdown(int sig);
int catch_signal(int sig, void (*handle_shutdown)(int));

int main(int argc, char *argv[]){
    if(catch_signal(SIGINT,handle_shutdown) == -1)
        error("Can't set the interrup handler");
    int sockfd = open_listener_socket();
    printf("Listerner Socekt: %i\n", sockfd);
    bind_to_port(sockfd, SIN_PORT);
    if (listen(sockfd, 20) == -1)
      error("Can't listen!!!");
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    puts("waiting for connection");
    char buf[255];
    while(1){
        int clnt_soc = accept (sockfd, (struct sockaddr *)&client_addr,
                &address_size);
//        send(clnt_soc, msg, strlen(msg), 0);
        if (clnt_soc == -1)
            error("Can't open second socket");
        if (say(clnt_soc,"<Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n>")
                != -1){
            read_in(clnt_soc, buf, sizeof(buf));
            if(strncasecmp("Who's there?", buf, 12))
                say(clnt_soc, "You should say 'Who's there?'!");
            else{
                if (say(clnt_soc, "Oscar\r\n> ") != -1){
                    read_in(clnt_soc, buf, sizeof(buf));
                    if(strncasecmp("Oscar who?", buf, 10))
                        say(clnt_soc,"You should say 'Oscar who?'!\r\n");
                    else
                        say(clnt_soc, "Oscar silly question, you get a silly answer\r\n");
                }
            }
        }
        close(clnt_soc);
    }        
return 0;
}
int catch_signal(int sig,void (*handle_shutdown)(int)){
    struct sigaction action;
    action.sa_handler = handler;
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


