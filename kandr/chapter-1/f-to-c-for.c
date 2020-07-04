#include <stdio.h>
//this is compacte program celsius-to-f.c using for loops

int main()
{
    float fahr;
    for (fahr = 0; fahr <= 300; fahr += 10)
        printf("%3.0f\t%6.1f\n", fahr, 5.0 / 9.0 * ( fahr - 32));

}
