#include <stdio.h>
//page 27 exercis 1-15
//print fahrenheit to celsius conversion table
//for fahr = 0, 20 ... 300
void convert_cmput(double fahr, int low, int upp, int step);

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
    convert_cmput(fahr, lower, upper, step);
    fahr = fahr + step;
    }

}


void convert_cmput(double fahr, int lower, int upper, int step)
{
        double celsius =  5.0 / 9.0 * ( fahr - 32 );
        printf("%3.0f\t%6.1f\n", fahr, celsius);
}    
