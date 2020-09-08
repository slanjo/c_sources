//MAY 22, 2020
//THis program shows static usage of linked lists

#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct my_struct {

    char *name;
    int age;
    struct my_struct *next;

} my_struct;


void display(my_struct *start);


int main(){
    
    my_struct cat = {"maca", 12, NULL};
    my_struct dog = {"ceno", 14, NULL};
    my_struct mouse = {"mis", 22, NULL};
    my_struct slanjo = {"Slanjo", 45, NULL};
    cat.next = &dog;
    mouse.next = &slanjo;
    dog.next = &mouse;
    display(&cat);   


	return 0;

}



void display(my_struct *start){
    my_struct *i = start;
    for( ; i != NULL; i = i->next){
        printf("Name: %s\nAge: %i\n", i->name, i->age);
    }

}
