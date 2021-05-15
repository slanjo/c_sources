//Redo a chapter two function with pointers
#include <stdio.h>
void strcat(char *, char *);
void strcat(char *, char *);

int main(){
    char *A = "Starting and then";
    char *B = "continuing";
    printf("%s", pstrat(&A, &B));
}

void strcat( char s[], char t[]){
    int i, j;

    i = j = 0;
    while (s[i] != '\0') /* find end of s*/
        i++;
    while ((s[i++] = t[j++] != '\0'))
        ;
}
void pstrcat( char *s, char *t){
    int i, j;

    i = j = 0;
    while ( *s != '\0') /* find end of s*/
        s++;
    while ((*s = *t != '\0'))
        ;
}