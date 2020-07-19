//Sun 19 Jul 2020 12:46:37 PM AWST
//exercise 2.5 page 48 
//write a function "any" which returns a first location(position) in string s1 where a 
//character from a string s2 occurs; or it will return a -1 if no character from s2
//occurs in s1.
//Standard library function 'strpbrk' does the same, but returns a pointer to the location 
#include <stdio.h>
int any(char a[], char b[]);
int main()
{
    char s1[99], s2[99];
    printf("Enter two strings: \n");
    scanf("%s %s", s1, s2);
    int f = any(s1, s2);
    printf(" is in position: %d\n", f);//any(s1, s2));

}
int any(char s1[], char s2[]){
    int i;
    int j;
    int k;
    char c;
    for (k = 0; s2[k] != '\0'; k++){
        c = s2[k];
        printf("c = %c\n", c);
        for (i = j = 0; s1[i] != '\0'; i++){
            if (c == s1[i]){
            printf("Character %c", s1[i]);
            return i;
            }
        }
    }
    return -1;    
//    printf("\n\n\ns1 is now: %s\n and s2 is %s\n", s1, s2);
}
