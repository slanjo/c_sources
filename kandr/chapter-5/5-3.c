//Redo a chapter two function with pointers
//Sat May 15 2021
#include <stdio.h>

void strcata(char [], char []);
void pstrcata(char [] , char []);

int main(){
    char A[] = "Blue";
    char B[] = "Black";
    pstrcata(A, B);
    printf("%s\n", A);
}
/*
void strcata( char s[], char t[]){
    int i, j;

    int i = j = 0;
    while (s[i] != '\0') // find end of s
        i++;
    while ((s[i++] = t[j++] != '\0'))
        ;
}*/
void pstrcata( char *s, char *t){
    printf("s = %c, t = %c\n", *s, *t);
    while ( *s != '\0' ){ /* find end of s*/
       s++;
    }
    printf("%s\n", *s);
    while ((*s++ = *t++))
        ;
}
