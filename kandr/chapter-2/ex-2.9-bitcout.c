//Sun 26 Jul 2020 07:45:40 PM AWST
//in a two's complement number system, x &= (x -1) deletes the rightmost 1-bit in x.
//Explain why? Use this observation to write a faster version of bitcount.
#include <stdio.h>
int bitcount(unsigned a);
int main(){
    unsigned a = 895;
    printf("Bit count for %d is: %d\n", a,  bitcount(a));
}
int bitcount(unsigned x){
    int b;
    for (b = 0; x != 0; x &= (x - 1))
            b++;

    
    return b;
}
/*int bitcount(unsigned x){
    int b;
    for (b = 0; x != 0; x >>= 1){
        if (x & 01)
            b++;
    }
    return b;
} */
