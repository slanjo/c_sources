//Wed 05 Aug 2020 05:35:14 AM AWST
//modify itoa from page 64 to print n = -(2^(wordsize-1)) correctly
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define AR_SIZE 100
void itoa(int n, char s[]);
char* reverse(char s[]);
int main(){
    int n;
    int sign;
    n = -2147483647;
    char s[AR_SIZE];
    itoa(n, s);
    return 0;
}
void itoa(int n, char s[]){
    int i, sign;

    if ((sign = n) < 0) //record the sign
        n = -n;
    i = 0;
    do {     //generate digits in reverse order
        s[i++] = n % 10 + '0';  //get next digit 
    } while ((n /= 10) > 0);     //delete it
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


