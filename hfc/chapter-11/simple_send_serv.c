//This is the first server from chapter 11 HFC that randomly sends a message to 
//a connected client. No input accespted from the client
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
//#include <error.h> 
#include <stdio.h>
#include <string.h>
#include <errno.h>
//if (c == -1)
//    error("Can't bind to socket");
void error(char *msg){
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}
int main(int argc, char *argv[]){
    char *advice[] = {
        "Take smaller bites\r\n",
        "Go for the tight jeans. No the do NOT make you look fat.\r\n",
        "One word: inappropriate\r\n",
        "Just for today, be honest. Tell your boss what you *really* think\r\n",
        "You might want to rethink that haircut\r\n"
    };
    int reuse = 1;
    int listener_d = socket(AF_INET, SOCK_STREAM, 0);
    if (listener_d == -1){
        error("Can't open socket");
    };
    if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *) &reuse, sizeof(int)) == -1)
        error("Can't set the reuse option on the socket");
    struct sockaddr_in name;
        name.sin_family = AF_INET;
        name.sin_port = (in_port_t)htons(30000);
        name.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(listener_d, (struct sockaddr *) &name, sizeof(name)) == -1)
        error("Can't bind the port");
    listen(listener_d, 10);
    puts("waiting for connection");
    while(1){
        struct sockaddr_storage client_addr;
        unsigned int address_size = sizeof(client_addr);
        int connect_d = accept (listener_d, (struct sockaddr *)&client_addr,
                &address_size);
        char *msg = advice[rand() % 5];
        send(connect_d, msg, strlen(msg), 0);
    }        
return 0;
}
