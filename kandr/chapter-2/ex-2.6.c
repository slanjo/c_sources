//Tue 21 Jul 2020 07:03:44 AM AWST
//K&R page 49 ex 2.6
//Write a function setbits(x, p, n, y) that return x with the n bits that begin at position
//p set to the rightmost n bits of y, leaving the other bits unchanged. 

#include <stdio.h>
int setbits( int a, int b,unsigned   int c,unsigned   int d);
int main(){
    int n, p, setbits_x;
    unsigned x, y;
/*    n = 3;
    x = 27;
    y = 10;
    p = 4; */
    n = 2;
    x = 255;
    y = 10;
    p = 8;
   int n_2 = 0;
//set bit mask to equivalent of n (3) which is 7:
//we left shift by 3 places with 0 complement which sets the 3 rightmost bits to 0
//then than we do one's complement to set rightmost 3 bits to "1". that equals 7
//then we to bitwise and to set y to the value of 3 rightmost bits - 3 in this case
//this can also be done manually by y = y & ~077770;
  
    n_2 = ~(~0 << n);
    y = y & n_2;
//    y = y | n_2;
    printf("y = %u\n", y);
//    y = y & ~077770;
    printf("n = %u\n", n);
    printf("n_2 = %u\n", n_2);
    printf("x = %i\n", setbits_x = setbits(n, p, x, y));

}
int setbits(int n, int p, unsigned int x, unsigned   int y){
//shift y to match x
    unsigned int mask_y, mask_x = 0;
    printf("n = %u\n", n);
    printf("y = %u\n", y);
//  set a mask to shield p - n + 1 bits with zeroes
//    mask  =  ~(~0 << (p - n + 1));
    mask_y  =  ~(~0 << (n));
    mask_x  =  ~(~0 << (p - n));
//  left shift y to the position p - 
//    y = y << (p - n + 1); 
    y = y << (p - n); 
    //    int y_shift = ( y << ( p + 1  - n ));   
    printf("mask_x: %u\n", mask_x);
    printf("mask_y: %u\n", mask_y);
    printf("y: %u\n", y);
    y = y | mask_x;
    printf("y after bitwise or: %u\n", y);
    x = x & y;
    return x;
}
