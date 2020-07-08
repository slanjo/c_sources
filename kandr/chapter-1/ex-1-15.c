#include <stdio.h>
//print fahrenheit to celsius conversion table
//for fahr = 0, 20 ... 300
int main()
{
//first version with ints
//int fahr, celsius;
//2nd with floats
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 10;
    fahr = lower;
    printf(" F        C\n");
    printf("-------------\n");
    while (fahr <= upper){
        celsius =  5.0 / 9.0 * ( fahr - 32 );
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
