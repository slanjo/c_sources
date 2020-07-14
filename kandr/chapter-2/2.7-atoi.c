//atoi: convert s to integer page 43
//
//the c > '0' && c <= '9'  can be done buy using isdigit(c)
//ctype.h provides a set of functions to test text characteristics
#include <stdio.h>
int atoi(char s[]);

int main()
{
    char s[999];
}
int atoi(char s[]){
    int i, n;
    n = 0;
    for (i = 0; s[i] > '0' && s[i] <= '9'; ++i){
        n = n * 10 + (s[i] - '0');
    }
    return n;
}
