//Sun 19 Jul 2020 01:27:01 PM AWST
//testing outcomes of logical operators
//
//
#include <stdio.h>
int main(){
    short int a, b, c, d;
    a = 0;
    b = 1;
    c = 2;
    d = 1;
    printf("a = %i, b = %i, c = %i, d = %i\n", a, b, c, d);
    printf("a && b = %i\n", a && b);
    printf("a & b = %i\n", a & b);
    printf("b && c = %i\n", b && c);
    printf("b & c = %i\n", b & c);
    printf("b & d = %i\n", b & d);
    printf("b && d = %i\n", b && d);

}
