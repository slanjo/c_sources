//Sat 08 Aug 2020 07:03:58 AM AWST
//modify itoa from page 3.4 to accept 3 arguments. third argument is a minimum 
//field width. The converted number must be padded with blanks on the left if necessary
//to make it wide enough. 
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define AR_SIZE 100
void itoa(int n, char s[], int width);
char* reverse(char s[]);
int main(){
    int n;
    int sign;
    int width = 30;
    printf("INT_MIN: %d\n", INT_MIN);
    n = INT_MIN;
    char s[AR_SIZE];
    itoa(n, s, width);
    return 0;
}
void itoa(int n, char s[], int width){
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
    while(strlen(s) <= width){
        s[i++] = 'x';
    }
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
