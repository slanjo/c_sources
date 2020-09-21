//Sat 19 Sep 2020 02:11:54 PM AWST
//reverse(s) reverses a string in place recursively
//
#include <stdio.h>
#include <stdlib.h>
char s[] = "abcdefghijhi";
int k = (sizeof(s) - 1) / 2;
void reverse(int, int);
int main()
{
    int i = 0 ;
    int j = sizeof(s) - 1;
    printf("j is %i\n", j); 
    printf("i is %i\n", i); 
    printf("string s is %s\n", s);
    reverse(i, j);
//    for (i = 0; i < sizeof(s); i++)
//        printf("' %c '\n", s[i]);

//    s[sizeof(s)] = '\0';
    printf("string s after recursion is %s\n", s);
    
//    printf("i is %i, and j is %i\n", i, j);
//    printf("s is %s\n", s);
    
}
void reverse(int i, int j)

{
    printf("k = %i\n", k);
    char c = s[i];
     if ((i <= k) && (j >= k) ){
        reverse(++i, --j);
    }
//    c = s[i];
    s[i] = s[j];
    s[j] = c;
    printf("s[%i] = %C, s[%i] = %c\n", i, s[i],j, s[j]);
//    printf("s is %s\n", s);
//    s[j++] = '\0';

}
