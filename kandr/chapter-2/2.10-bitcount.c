//Sat 25 Jul 2020 08:49:26 PM AWST
#include <stdio.h>
int bitcount(unsigned a);

int main(){

    
}

int bitcount(unsigned x){
    int b;
    for (b = 0; x != 0; x >>= 1){
        if (x & 01)
            b++;
    }
    return b;
}
