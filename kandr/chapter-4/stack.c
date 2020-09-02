//Wed 19 Aug 2020 04:46:51 AM AWST
#include <stdio.h>
#define MAXVAL 100      //maximum depth of val stack

int sp = 0;             //next free stack position
int k = 0;
double val[MAXVAL];     //value stack
//push: push f onto value stack

void push(double f){
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, cant' push %g\n", f);
}
//pop: pop and return top value from stack
double pop(void){
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
double prn(void){
    if (sp < MAXVAL){
        return val[sp]; 
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
