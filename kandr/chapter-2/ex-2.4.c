//exercise 2.4 pate 48 
//write an alternate version of squeeze - squeeze(s1, s2) where each char that exists
//in both s1 and s2 is removed from s1
#include <stdio.h>
//enum hexa {A = 10, B = 11, C = 12, D = 13, E = 14, F = 15, a = 10, b = 11, c = 12,
//        d = 13, e = 14, f = 15};
void squeeze(char s1[], char s2[]);
int main()
{
    char s1[99], s2[99];
    printf("Enter two strings: \n");
    scanf("%s %s", s1, s2);
    squeeze(s1, s2);

}

void squeeze(char s1[], char s2[]){
    int i, j = 0;
    
    printf("s1 is now: %c\n", s1[0]);
    

}
