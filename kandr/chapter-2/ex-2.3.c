//htoi: convert string of HEX digits to integer page 46
//
//the c > '0' && c <= '9'  can be done buy using isdigit(c)
//ctype.h provides a set of functions to test text characteristics
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//enum hexa {A = 10, B = 11, C = 12, D = 13, E = 14, F = 15, a = 10, b = 11, c = 12,
//        d = 13, e = 14, f = 15};
void htoi(char s[],int len);

int main()
{
    char s[99];
    printf("Enter your hex num: \n");
    scanf("%s", s);
    printf("s[0] = %d\n", s[0]);
    htoi(s, strlen(s));//strlen excludes the sentinel character '\0'
    
}
void htoi(char s[], int size){
    int i, n;
    printf("s[0] = %d\n", s[0]);
    n = 0;
    for (i = 0; (isxdigit(s[i])) != 0 && s[i] != '\0'; ++i){
        if ( s[i] >= 'A' && s[i] <= 'F')
            n = n * 16 + (s[i] - '0') - 7;
        else if ( s[i] >= 'a' && s[i] <= 'f')
            n = n * 16 + (s[i] - '0') - 39;
        else // ( s[i] >= 'A' && s[i] <= 'F')
            n = n * 16 + (s[i] - '0');
    }
    printf("Integer equvalnet is: %i\n", n);
}
