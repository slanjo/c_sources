#include <stdio.h>

int main()
{
    int c = 8;
    int *p;
    *p = c;
    printf("c = %i\n*p = %i\n&p = %p\n&c = %p\n",c, *p, &p, &c);
    p = &c;
    printf("c = %i\n*p = %i\n&p = %p\n&c = %p\n",c, *p, p, &c);
}
