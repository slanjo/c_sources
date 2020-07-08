#include <stdio.h>
//this program is the equivalent of stdlib pow(x, y), but it can only take 
//a positive integer as its power argument.  
//1.7 page 24 k&r
int power(int m, int n);
int main()
{
    int i;
    for (i = 0; i <= 10; i++)
        printf("%d %d %d\n", i, power(2,i), power(-3, i));
    return 0;
}
int power(int base, int n){
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return(p);
}
