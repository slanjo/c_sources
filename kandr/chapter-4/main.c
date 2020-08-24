//Wed 19 Aug 2020 05:11:32 AM AWST
//chapter 4.3 page 76 - Reverse Polish Calculater
#include <stdio.h>
#include <stdlib.h> //to get atof()
#include "calc.h"
//#define MAXOP 100   // max size of operand or operator

main()
{
    int type;
    double op2;
    char s[MAXOP]; 
    
    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case NEG_NUMS:
                push(atof(s));
                break; 
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
//Exercise 4.3 Modulus and Negative numbers
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push( (int) pop() % (int) op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
