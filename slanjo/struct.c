//MAY 22, 2020
//Sanjin Zoric
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
    
    my_struct dane = {"Dane", 12, NULL};
    my_struct sonja = {"Sonja", 14, NULL};
    my_struct ljiljana = {"Ljilja", 22, NULL};
    my_struct slanjo = {"Slanjo", 45, NULL};
    dane.next = &sonja;
    ljiljana.next = &slanjo;
    sonja.next = &ljiljana;
    display(&dane);   


	return 0;

}



void display(my_struct *start){
    my_struct *i = start;
    for( ; i != NULL; i = i->next){
        printf("Name: %s\nAge: %i\n", i->name, i->age);
    }

}
