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
    int size = 0;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-') /* && c != '-'*/
        return c;               //not a number
    i = 0;
//solution 4.3 
    if  ((c == '-') && (isdigit(s[++i] = k = getch()))){
        if (isdigit(k)){
            while (isdigit(s[++i] = k = getch()))
            ;
        }
        if (k == '.'){
            while (isdigit(s[++i] = k = getch()))
            ;
        }
        s[i] = '\0';
        s[0] = '-';
        if (k != EOF)
            ungetch(k);
        return NUMBER;
    }
    else if (c == '-')
       return c; 
    i = 0;
    if (isdigit(c))  {                      //collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    } 
    if (c == '.'){                               //collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
