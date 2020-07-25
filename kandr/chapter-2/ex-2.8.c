//Sat 25 Jul 2020 12:19:20 PM AWST
//K&R ex 2.8 
//Write a function rightrot (x, n) that returns "x" rotated to the right by n
//positions
#include <stdio.h>
int rightrot(int x, int n);
int main(){
    int x, n;
    x = 16;//186;
    n = 5; 
    printf("x(%d) right rotated by %d places is: %d\n", x, n, rightrot(x, n));

    return 0;

}
int rightrot(int x, int n){
    int x_cp = x;           // used to figure out the length of the binary for each x\
                            used to shift rightmost bit of x into leftmost bit position
    int p, i = 0;           //p = number of positions for each x
    int x_lth = 0;          //xlt(low to high) = x Lowest order bit To Highest order \
                            bit - used to shift left most bit of x to the right 

    int y = 1;
    while (x_cp > 0){       //Check out the length of x in binary \
                            (the number of binary places required for x)
        x_cp = x_cp / 2;
        p++;
    }
    x_cp = x; //set x_cp
    int n_bits_mask = ~(~0 << y); //create a far-right 1's mask
    for (i = 0; i < n; i++){
        x_lth = (x & n_bits_mask) << (p - 1); //shift rightmost bit of x to leftmost\
                                              bit of x i.e. ROTATE
        x = (x >> 1) + x_lth; 
    }
    return x;
}
