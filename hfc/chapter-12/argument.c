#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void error(char* msg);
int main(){


}

void error(char* msg){
    fprintf(stderr,"%s: %s\n", msg, strerror(errno));
    exit(1);
}
