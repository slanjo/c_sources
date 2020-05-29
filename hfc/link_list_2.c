#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

//This program folows chapter 6 and linked list lectures: PAGE 288
typedef struct island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
}island;
void release(island *start);
void display(struct island *start);
island* create(char *name);

int main(){
    char name[80];
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;
//    FILE *file_pt = fopen("isle.txt", "r");

    for (; fgets(name, 80, stdin) != NULL; i = next){
        next = create(name);
        if (start == NULL)
            start = next;
        if (i != NULL)
           i->next = next;
    }
    display(start);
    release(start);
    return 0;
}
void display(island *start){
    struct island *i = start;
    for (; i != NULL; i = i->next){
        printf("Name: %s\n open: %s-%s\n", i->name, i->opens, i->closes);
    } 
}

island* create(char *name){
    island *i = malloc(sizeof(island));
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}
void release(island *start){
    island *i = start;
    island *next = NULL;
    for (; i != NULL; i = next) {
        next = i->next;
        free(i->next);
        free(i);
    }
}
