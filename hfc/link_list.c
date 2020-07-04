#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

//This program folows chapter 6 and linked list lectures:
typedef struct island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

void display(island *start);
island* create(char *name);

island amity = {"Amity", "09:00", "17:00", NULL};
island craggy = {"Craggy", "09:00", "17:00", NULL};
island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
island shutter = {"Shutter", "09:00", "17:00", NULL};
island skull = {"Skull", "09:00", "17:00", NULL};


int main(){

    amity.next = &craggy; 
    craggy.next = &isla_nublar;
    isla_nublar.next = &shutter;
    skull.next = &shutter;
    printf("address of amity.next before function call is %p\n", &amity);
//    display(amity.next);
    display(&amity);
	return 0;
}

void display(island *start){
    island *i = start;
    printf("address of amity after the function call is %p\n", i);

    for (; i != NULL; i = i->next){
        printf("Name: %s\n open: %s-%s\n", i->name, i->opens, i->closes);
    } 



}
