#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    char* name;
    int age;
    struct lista* next;
}lista;

int main(){
    char name[20];
    int age;
    lista *start = NULL;
    lista *l = NULL;
    lista *next = NULL;
    if (start == NULL){
       while(!'\0'){ 
        scanf("Enter User Name: %s", &name);
//        printf(start->name);
//        printf("Enter name: ");
//        fgets(name, sizeof(name), stdin);
//        scanf("Enter age %i", &age);
//        start->name = name; 
//        start->age = age;
        }
        printf("Output %s", start->name);
//        scanf("Enter age: %d", &(start->age));
    }
}
