//Tue 25 Aug 2020 06:10:45 AM AWST
//solution for "-" taken from: Xggggg @ //https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_4:Exercise_3
#include <stdio.h>
#include <ctype.h>
#include "calc.h"
int getop(char s[])
{
    int i = 0, c, k;
        while ((s[0] = c = getch()) == ' ' || c == '\t')
            ;
        s[1] = '\0';
        if (isdigit(c) || c == '.' || ((c == '-' || c == '+') && (isdigit(k = getchar()) || k == '.')))
           {
               if (c == '-' || c == '+')
                   s[++i] = c = k;
               if (isdigit(c))
                   while (isdigit(s[++i] = c = getch()));
               if (c == '.')
                    while (isdigit(s[++i] = c = getch()));
                s[i] = '\0';
                if (c != EOF)
                   ungetch(c);
                c = NUMBER;
             }
        if (c == '-' || c == '+')
            ungetch(k);
        return c;
}
