//Tue 28 Jul 2020 04:40:13 AM AWST
#include <stdio.h>
#include <stdlib.h>
int binsearch(int x, int v[], int n);
int binsearch_one_test(int x, int v[], int n);
int compar (const void* p1, const void *p2);
int main(){
    int v[1000], i, j, n, x;
    x = 43;
    for (i = 0; i < 1000; i++)
        v[i] = rand() % 1000;
    n = sizeof(v) / sizeof(int);
    qsort(v, 1000, sizeof(int), compar);
    for (i = 0; i < n; i++)
       printf("%i\n", v[i]); 
    printf("n is: %d\n", n);
    printf("The element x is at location %d of the array. \n", binsearch(x, v, n));




}
int binsearch(int x, int v[], int n){
    int low, mid, high;
    v[500] = 43;
    printf("v[499] is %d\n", v[499]);
    printf("v[500] is %d\n", v[500]);

    mid = high = low = 0;
    high = n - 1;
    while (low <= high){
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}
/*
int binsearch_one_test(int x, int v[], int n){
    int low, mid, high;
    low = 0;
    high = n - 1;
    while (low <= high){
        mid = high / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;

    }
    return -1;
}*/

int compar(const void* p1, const void* p2){
    return (*(int*) p1 > *(int *)p2);
}
