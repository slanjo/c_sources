//Tue 04 Aug 2020 06:25:24 AM AWST
//itoa convert an integer n to characters in s
#include <stdio.h>
#include <string.h>
#define AR_SIZE 100
void itoa(int n, char s[]);
char* reverse(char s[]);
int main(){
    int n, sign;
    n = 65;
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


