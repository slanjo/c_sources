#include <stdio.h>

/* printd: print n in decimal */
char s[10];
int i = 0;
int itoai(int n, int i, char s[]);


int main(){
   int x = -123456;
//   printf("string s = %s\n", itoai(x, i, s));
}

int itoai(int n, int i, char s[])
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    i++;
//    char s[10];   
/*if (n / 10)
    printd(n / 10);
putchar(n % 10 + '0');
*/
    if (n / 10) {
        s[i] = itoai((n % 10 + '0'), i, s);
    }
    s[i] = n % 10 + '0';
    printf("\n" ); 
        

}
