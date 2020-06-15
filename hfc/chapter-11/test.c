#include <stdlib.h>
#include <stdio.h>
int main(){
    char  *somestring[] = {"first string", "second"};
    printf("%p\n", somestring);
    printf("%p\n", &(*somestring));
    printf("%p\n", *somestring);
    printf("%p\n", &somestring);
    printf("%s\n", *somestring);
}
