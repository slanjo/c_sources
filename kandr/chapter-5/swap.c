//this is a function that will swap two ints using pointers
#include <stdio.h>
void swap(int *, int *);
int main()
{
    int *a, *b;
    int x = 10;
    int y = 10000;
    a = &x;
    b = &y;
    printf("a = %i\n b = %i\n", *a, *b);
    printf("a = %p\n b = %p\n", &a, &b);
    printf("adress of a before swap: %p\n", &a);
    printf("adress of b before swap: %p\n", &b);
    swap(a, b);
    printf("AFTER SWAP\n==========\n");
    printf("a = %i\nb = %i\n", *a, *b);
    printf("a = %p\nb = %p\n", &a, &b);
    return 0;
}


void swap(int *pa, int *pb)
{
    printf("adress of a inside swap: %p\n", &pa);
    printf("adress of b inside swap: %p\n", &pb);
    int temp = 0;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}   
