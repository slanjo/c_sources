//htoi: convert string of HEX digits to integer page 46
//
//the c > '0' && c <= '9'  can be done buy using isdigit(c)
//ctype.h provides a set of functions to test text characteristics
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//enum hexa {A = 10, B = 11, C = 12, D = 13, E = 14, F = 15, a = 10, b = 11, c = 12,
//        d = 13, e = 14, f = 15};
void htoi(char s[]);

int main()
{
    char s[99];
//    int lead_0X;//used to notify the function if we're passing a string with "0x"
    unsigned long lead_0X;
    printf("Enter your hex num: \n");
    scanf("%s", s);
    printf("s[0] = %d\n", s[0]);
    htoi(s);
    /*
    if (s[0] == '0' && ( s[1] == 'x' || s[1] == 'X'))
        htoi(s, lead_0X = 2);
    else
        htoi(s, (unsigned) strlen(s));//strlen excludes the sentinel character '\0'
        */
}
void htoi(char s[]){
    unsigned long int n;
    int i, k;
    printf("s[0] = %d\n", s[0]);
    n = 0;
    if (s[0] == '0' && ( s[1] == 'x' || s[1] == 'X'))
        k = 2;
    else
        k = 0;
    for (i = k; (isxdigit(s[i])) != 0 && s[i] != '\0'; ++i){
        if ( s[i] >= 'A' && s[i] <= 'F')
            n = n * 16 + (s[i] - '0') - 7;
        else if ( s[i] >= 'a' && s[i] <= 'f')
            n = n * 16 + (s[i] - '0') - 39;
        else // ( s[i] >= 'A' && s[i] <= 'F')
            n = n * 16 + (s[i] - '0');
    }
    printf("Integer equvalnet is: %li\n", n);
}
