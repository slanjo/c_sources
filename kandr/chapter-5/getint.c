#include <ctype.h>
#include "/home/slanjo/Programming/C/kandr/chapter-4/getch.c"
int getint(int *pn);
int main()
{
    int SIZE = 10;
    int n, array[SIZE], getint(int *);
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
            ;
    for (int i = 0; i < SIZE; i++)
        printf("digit %i: %i\n", i, array[i]);
}
int getint(int * pn)
{
    int c, sign;
    while (isspace(c = getch()))  //skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
            ungetch(c);
            return 0;
            }
    sign = (c == '-') ? - 1 : 1;
    if ( c == '+' || c == '-')
        c = getch();
    if (!isdigit(c))
        ungetch(c);
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if ( c != EOF )
        ungetch(c);
    return c;
}
    
