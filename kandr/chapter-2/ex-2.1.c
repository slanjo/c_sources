#include <stdio.h>
#include <limits.h>
#include <float.h>
//write a program that determines the ranges of char, integer, short, and long 
//both signed and unsigned
//
int main()
{
    int r = 0;
/*    for(int i = 0; i < 100; i++)
    {
        r = i & 0177;
        printf("i & 1: %d\n", r);
    }
*/


    printf("CHAR_MIN is: %i\n", CHAR_MIN);
    printf("CHAR_MAX is: %i\n", CHAR_MAX);
    printf("UCHAR_MAX is: %i\n", UCHAR_MAX);
    printf("SHRT_MIN is: %d\n", SHRT_MIN);
    printf("SHRT_MAX is: %d\n", SHRT_MAX);
    printf("USHRT_MAX is: %d\n", USHRT_MAX);   
    printf("INT_MIN is: %d\n", INT_MIN);
    printf("INT_MAx is: %d\n", INT_MAX);
    printf("UINT_MIN is: %u\n", UINT_MAX);
    printf("INT_MIN is: %d\n", INT_MIN);
    printf("INT_MIN is: %d\n", INT_MIN);

}
