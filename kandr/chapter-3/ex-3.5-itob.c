//Thu 06 Aug 2020 05:24:05 AM AWST
//write itob(n, s, b) to convert the integer n into a base b character representation in string s. 
//i.e. ntob(n, s, 16) is a hexadecimal integer s. 
//
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define AR_SIZE 100
enum hexa {A = 10, B = 11, C = 12, D = 13, E = 14, F = 16}; 
void itob(unsigned int n, char s[], int b);
char* reverse(char s[]);
int main(){
    int n, b, k;
    int sign;
    int test[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 11, 12, 13, 14, 15, 16, 17, 3003, 256, 2782};
    b = 16;
//    printf("INT_MIN: %d\n", INT_MIN);
//    n = INT_MIN;
//    n = 3003;
//    n = 3003;
    char s[AR_SIZE];
    for (k = 0; k < 20; k++)
        itob( test[k], s, b);
    return 0;
}
void itob(unsigned int n, char s[], int b){
    int i, sign;
    unsigned int n2, n3;
    n2 = n; 
    if ((sign = n) < 0) //record the sign
        n2 = -n;
    i = 0;
    do {     //generate digits in reverse order
        if (((n3 = (n2 % b)) <= 16) && (n3 >= 10)){ 
            s[i++] = n3 + (7 + '0');  //get next digit 
            printf("String(IF) is: %i\n", n2 % b );
        }
        else
            s[i++] = (n3 = (n2 % b)) + '0';
            printf("String(ELSE) is: %i\n", n2 % b );
   } while ((n2 /= b) > 0);  //while (n /= 10); //w   //delete it
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    printf("string is: %s\n", reverse(s));
}
/*
void reverse(char s[]){

    int c, i, j;
    for (i = 0, j = strlen(s) -1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        }
}
*/
char* reverse(char s[]){
    int c, i, j;
    for (i = 0, j = strlen(s) -1; i < j; i++, j--) {
    c = s[i], s[i] = s[j], s[j] = c;
    }
    return (s);
}
