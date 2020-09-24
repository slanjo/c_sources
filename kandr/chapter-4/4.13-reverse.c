//Sat 19 Sep 2020 02:11:54 PM AWST
//reverse(s) reverses a string in place recursively
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[] = "ab";
//char s[] = "abcde";
//char s[] = "Z Y X W V U T S R Q P O N M L K J I H G F E D C B A";
//char s[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
void reverse(int, int);
int main()
{
    int i = 0;
    int j = strlen(s); //- 1;
    printf("j is %i\n", j); 
    printf("i is %i\n", i); 
    printf("string s is %s\n", s);
    reverse(i, j - 1 );
    char k = s[i];
    s[i] = s[j - 1];
    s[j - 1] = k;

    printf("string s after recursion is %s\n", s);
}
void reverse(int i, int j)

{
    char c;
   if (i < j) 
       reverse(++i, --j);
    if (i == j) 
        ;
    if (i != j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        printf("s[%i] = %C, s[%i] = %c\n", i, s[i],j, s[j]);
    }
    return;
}
