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
//Exercise 4.4 Print top of the stack without Pop
double prn(void){
    if (sp < MAXVAL){
        return val[sp-1]; 
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
        }
    }
//Exercise 4.4 Clear the TOP of the stack. To clear the whole stack
//we'd need a for loop to zero the whole val array.  
double clr(void){
    if (sp < MAXVAL){
       val[--sp] = 0;
       return val[sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
//Exercise 4.4 duplicate the TOP of the stack. 
void dpl(void){
    if (sp < MAXVAL){
        k = sp - 1;
        val[sp] = val[k];
    }
    else
        printf("error: stack full, cant' push %g\n", val[k]);
}
//Exercise 4.4 Swap top two values on the stack
void swp(void){
    if (sp < MAXVAL){
        double temp = 0;
        int j = sp - 1;
        int l = sp - 2;
        temp = val[j];
        val[j] = val[l];
        val[l] = temp;
    }
    else
        printf("error: stack full, cant' push %g\n", val[k]);
}
