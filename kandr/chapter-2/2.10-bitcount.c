//Sat 25 Jul 2020 08:49:26 PM AWST
//K&R 2.10 page 50
#include <stdio.h>
int bitcount(unsigned a);
int main(){
    unsigned a = 255;
    printf("Bit count for %d is: %d\n", a,  bitcount(a));
}

int bitcount(unsigned x){
    int b;
    for (b = 0; x != 0; x >>= 1){
        if (x & 01)
            b++;
    }
    return b;
}
