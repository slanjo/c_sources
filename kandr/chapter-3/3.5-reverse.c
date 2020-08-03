//Tue 04 Aug 2020 06:14:17 AM AWST
//reverse a string in place
#include <stdio.h>
#include <string.h>
void reverse(char s[]){

    int c, i, j;
    for (i = 0, j = strlen(s) -1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }    
}
/*
void reverse(char s[]){
    int c, i, j;
    for (i = 0, j = strlen(s) -1; i < j; i++, j--) {
        c = s[i], s[i] = s[j], s[j] = c;
        }
    }
*/
