//Wed 05 Aug 2020 05:35:14 AM AWST
//modify itoa from page 64 to print n = -2^(wordsize-1)(i.e. the 'largest'
//negative number correctly
//used help from https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_3:Exercise_4
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define AR_SIZE 100
void itoa(int n, char s[]);
char* reverse(char s[]);
int main(){
    int n;
    int sign;
    printf("INT_MIN: %d\n", INT_MIN);
    n = INT_MIN;
    char s[AR_SIZE];
    itoa(n, s);
    return 0;
}
void itoa(int n, char s[]){
    int i, sign;
    unsigned int n2;
    sign = n;
    if ((sign = n) < 0) //record the sign
        n2 = -n;
    i = 0;
    do {     //generate digits in reverse order
        s[i++] = (n2 % 10) + '0';  //get next digit 
    } while ((n2 /= 10) > 0);  //while (n /= 10); //w   //delete it
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
