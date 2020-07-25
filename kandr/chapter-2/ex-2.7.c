//k&r page ex-2.7 page 49
//started Wed 22 Jul 2020 08:56:28 PM AWST
//Write a function invert(x, p, n) that returns a set of bits (n) out of 
//integer x inverted, starting @ position p.
#include <stdio.h>
int invert(unsigned a, unsigned int b, unsigned int c);
int main(){
    unsigned int x; 
    unsigned int n, p;
    x = 186;
    n = 2;
    p = 5;
    int i;
    printf("x(%d) with inverted n(%d) bits at position p(%d) is: %d \n", x, n, p, invert(x, p, n)); 


}
int invert(unsigned x, unsigned p, unsigned n){
    unsigned int x_mask, x_copy, n_bits, x_copy_1;
    x_copy = x;
    x_copy_1 = x;
    int i;
    int num_bin_dig;
//    while (x_copy_1 > 0){
//        x_copy_1 = x_copy_1 / 2;
//        num_bin_dig++;
//    }
    x_mask = ~(~0 << n); //create a mask with 0s at far right "n" positions
    x_mask = x_mask << (p + 1 - n);
    x = x ^ x_mask;
//    n_bits = (x_copy >> ( p + 1 - n) & ~(~0 << n)); 
//    printf("n-bits = %d\n", ~n_bits);


    return x;
}
