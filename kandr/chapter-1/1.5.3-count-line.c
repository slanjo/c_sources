#include <stdio.h>

//count input lines


int main()
{
    int nl, counter;

    while((nl = getchar()) != EOF){
        if (nl == '\n')
            ++counter;
        printf("counted %d lines\n", counter);
    } 
}
