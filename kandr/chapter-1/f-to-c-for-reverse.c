#include <stdio.h>
//this is compacte program celsius-to-f.c using for loops
#define UPPER 300
#define LOWER 0
#define STEP 10
int main()
{
    float fahr;
    for (fahr = UPPER; fahr >= LOWER; fahr -= 10)
        printf("%3.0f\t%6.1f\n", fahr, 5.0 / 9.0 * ( fahr - 32));

}
