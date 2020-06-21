#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
void error(char* msg);
void * does_not(void* a);
void * does_too(void* a);

int main(){
//pthread is a datastructure to be loaded with thread in
    pthread_t t0;
    pthread_t t1;
//ptread_create creates a new thread and runs it
    if (pthread_create(&t0, NULL, does_not, NULL) == -1)
        error("Can't create thread t0");
    if (pthread_create(&t1, NULL, does_too, NULL) == -1)
        error("Can't create thread t1");
    void* result;
//pthread_join waits for a thread to finish
    if (pthread_join(t0, &result) == -1)
        error("Can't join thread t0");
    if (pthread_join(t1, &result) == -1)
        error("Can't join thread t1");



}
void error(char* msg){
    fprintf(stderr,"%s: %s\n", msg, strerror(errno));
    exit(1);
}
void * does_not(void* a){
    int i = 0;
    for (i = 0; i <5; i++){
        sleep(1);
        puts("Does not!");
    }
    return NULL;
}
void * does_too(void *a){
    int i = 0;
    for (i = 0; i < 5; i++){
        sleep(1);
        puts("Does too!");
    }
    return NULL;
}
