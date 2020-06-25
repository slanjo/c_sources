#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
long beers = 20000000000;
void* drink_lots(void *a);
pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;
int main(){
    pthread_t threads[30];
    int t;
    printf("%ld bottles of beer on the wall\n%ld bottles of beer\n", beers, beers);
    for (t = 0; t < 30; t++){
        pthread_create(&threads[t], NULL, drink_lots, NULL);
    } 
    void* result;
    for (t = 0; t < 30; t++){
        pthread_join(threads[t], &result);
    }
    printf("There are now %ld bottles of beer on the wall\n", beers);
    return 0;
}
void* drink_lots(void *a){
    int i;
    pthread_mutex_lock(&beers_lock);
    for (i = 0; i < 1000000000; i++){
//       pthread_mutex_lock(&beers_lock);
       beers = beers - 1;
//       pthread_mutex_unlock(&beers_lock);
   }
    pthread_mutex_unlock(&beers_lock);
    printf("beers = %ld\n", beers);
    return NULL;
}
