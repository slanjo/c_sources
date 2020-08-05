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
void itob(int n, char s[], int b);
char* reverse(char s[]);
int main(){
    int n, b;
    int sign;
    b = 16;
    printf("INT_MIN: %d\n", INT_MIN);
//    n = INT_MIN;
//    n = 256;
    n = 256;
    char s[AR_SIZE];
    itob(n, s, b);
    return 0;
}
void itob(int n, char s[], int b){
    int i, sign;
    unsigned int n2, n3;
    n3 = (A || B || C || D || E || F);
    sign = n;
    if ((sign = n) < 0) //record the sign
        n2 = -n;
    i = 0;
    do {     //generate digits in reverse order
        if ((n3 = n2 % b) == (A || B || C || D || E || F)){
            s[i++] = n3 + '0';  //get next digit 
            printf("Code is: %i\n", n2 % b );
        }
        else
            s[i++] = (n3 = (n2 % b)) + '0';
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
