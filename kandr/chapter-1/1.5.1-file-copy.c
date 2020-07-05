#include <stdio.h>
//copy input to output

int main(){
    int c;
    
    printf("getchar () != EOF is: %i", (getchar() != EOF));
//    printf("The value of EOF is %d\n", EOF);
//    c = getchar();
//    while (c != EOF){
    while((c = getchar()) != EOF){
        printf("getchar () != EOF is: %d\n", (c != EOF)); 
        putchar(c);
 //       c = getchar();
    }
}
