#include <stdio.h>

//exercise 1.9 page 20, replace one ore more blanks with a single blanks


int main()
{
    int nl, tb, bl, counter, bs, bl_count;
    bs = nl = tb = bl = counter = 0;
    while((counter = getchar()) != EOF){
        if (counter ==  '\t')
            printf("\\t");
        if ( counter == '\b')
            printf("\\b");
        else if(counter == '\\')
            printf("\\");
        putchar(counter);
    } 
}


