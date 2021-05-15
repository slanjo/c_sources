#include <stdio.h>
void strcat(char *, char *);
void strcat(char *, char *);
int main(){

}

void strcat( char s[], char t[]){
    int i, j;

    i = j = 0;
    while (s[i] != '\0') /* find end of s*/
        i++;
    while ((s[i++] = t[j++] != '\0'))
        ;
}
void pstrcat( char s[], char t[]){
    int i, j;

    i = j = 0;
    while (s[i] != '\0') /* find end of s*/
        i++;
    while ((s[i++] = t[j++] != '\0'))
        ;
}