#include <stdio.h>
//count the number of characters in input

int main(){
/*  while loop exmaple  
    long nc;
    nc = 0;
    while(getchar() != EOF){
        ++nc;
        printf("%ld\n", nc);
    }
    //ld is "long integer specifier"
*/ 
//for loop example
    double nc;
    for(nc = 0;getchar() != EOF; ++nc)
        ;
     printf("%.0f\n", nc); 
//
    return 0;
}
