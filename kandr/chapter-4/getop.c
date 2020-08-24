//Tue 18 Aug 2020 05:05:18 AM AWST
//getop: get next operator or numeric operand
#include <stdio.h>
#include <ctype.h>
#include "calc.h"
int getch(void);
void ungetch(int);
int getop(char s[]){
    int i, c, k, sign;
    sign = 1;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-') /* && c != '-'*/
        return c;               //not a number
    i = 0;
    
    if ( (c == '-') && (isdigit(s[++i] = c = getch()))) {
        while (isdigit(s[++i] = c = getch()))   //collect integer part
            ;
    } 
    else //(c == '-')
        return c;
    if (isdigit(c)) {                      //collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    /*solution from https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_4:Exercise_3 menonsahab's 
    if (c == '-')
    {
        k = getch();
        if(k == ' ')
            return c;
        else 
            ungetch(k);
    }*/
    if (isdigit(c))  {                      //collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    } 
    if (c == '.')                               //collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
