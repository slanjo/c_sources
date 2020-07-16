//exercise 2.5 page 48 
//write a function "any" which returns a first location(position) in string s1 where a 
//character from a string s2 occurs; or it will return a -1 if no character from s2
//occurs in s1. 
#include <stdio.h>
//enum hexa {A = 10, B = 11, C = 12, D = 13, E = 14, F = 15, a = 10, b = 11, c = 12,
//        d = 13, e = 14, f = 15};
void squeeze(char a[], char b[]);
int main()
{
    char s1[99], s2[99];
    printf("Enter two strings: \n");
    scanf("%s %s", s1, s2);
    squeeze(s1, s2);

}
void squeeze(char s1[], char s2[]){
    int i;
    int k;
    int j;
    char c;
    for (k = 0; s2[k] != '\0'; k++){
        c = s2[k];
        printf("c is now; %c\n", s2[k]);
        for (i = j = 0; s1[i] != '\0'; i++){
            if (s1[i] != c)
                s1[j++] = s1[i];
            }
        s1[j] = '\0';
        printf("s1 end of loop: %s\n", s1);
    }
//    printf("a single char of s1 =: %c\n", s2[j + 0]);
    printf("\n\n\ns1 is now: %s\n and s2 is %s\n", s1, s2);
}
