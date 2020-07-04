#include <stdio.h>
//print celsius to fahrenh conversion table
//for celsius = 0, 1, 2 ... 300
int main()
{
//first version with ints
//int fahr, celsius;
//2nd with floats
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 100;
    step = 1;
    fahr = lower;
    printf(" C        F\n");
    printf("-------------\n");
    while (celsius <= upper){
        fahr = celsius * 9.0 / 5.0 + 32;
//        celsius =  5.0 / 9.0 * ( fahr - 32 );
        printf("%3.0f\t%6.0f\n", celsius, fahr );
        celsius += step;
    }
}
