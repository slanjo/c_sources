//k&r page ex-2.7 page 49
//started Wed 22 Jul 2020 08:56:28 PM AWST
//Write a function invert(x, p, n) that returns a set of bits (n) out of 
//integer x inverted, starting @ position p.
#include <stdio.h>
int invert(unsigned a, unsigned int b, unsigned int c);
int main(){
    unsigned int x; 
    unsigned int n, p;
    x = 170;
    n = 2;
    p = 6;
    int i;
    invert(x, p, n); 


}
int invert(unsigned x, unsigned p, unsigned n){
    unsigned int x_mask, x_copy, n_bits, x_copy_1;
    x_copy = x;
    x_copy_1 = x;
    int i;
    int num_bin_dig;
    while (x_copy_1 > 0){
        x_copy_1 = x_copy_1 / 2;
        num_bin_dig++;
    }
    printf("num_bin_dig: %i\n", num_bin_dig);
    x_copy = x_copy >> ( p + 1 - n);
    printf("x_copy = %d\n", x_copy);
    n_bits = x_copy & ~(~0 << n);        
//    n_bits = (x_copy >> ( p + 1 - n) & ~(~0 << n)); 
    printf("n_bits = %d\n", n_bits);


    return x;
}
