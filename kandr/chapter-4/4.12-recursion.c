#include <stdio.h>

/* printd: print n in decimal */
char s[10];
int i = 0;
void itoai(int n);


int main(){
   int x = -123456;
   int i = 0;
   
   itoai(x);
   printf("%s", s);
}

void itoai(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) {
        itoai(n/10);
    }
    s[i++] = n % 10 + '0';
    s[i] = '\0'; 
}
