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
    if  (c == '-')  {
        if (isdigit(k = getch())){
            if ((k != EOF) && (k != ' '))  {
                s[1] = k;
                s[2] = '\0';
//                ungetch(k);
                c = k;
            }
            else 
                return c;
        }
    }
    i = 1;
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
