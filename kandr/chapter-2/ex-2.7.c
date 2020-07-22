//k&r page ex-2.7 page 49
//started Wed 22 Jul 2020 08:56:28 PM AWST
//Write a function invert(x, p, n) that returns a set of bits (n) out of 
//integer x inverted, starting @ position p.
#include <stdio.h>
int invert(unsigned a, unsigned int b, unsigned int c);
int main(){
    unsigned int x; 
    unsigned int n, p;
    x = 87;
    n = 2;
    p = 6;
    invert(x, p, n); 


}
int invert(unsigned x, unsigned p, unsigned n){
    unsigned int x_mask, x_copy, n_bits;
    x_copy = x;
    n_bits = (x >> ( p + 1 - n) & ~(~0 << n)); 
    printf("n-bits = %d\n", n_bits);


    return x;
}
