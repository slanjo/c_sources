//Mon 27 Jul 2020 09:57:21 PM AWST
//Convert upper to lower case
//
#include <stdio.h>
int lower(int c);
int main(){
    char c = 'A';
    printf("small %c\n", lower(c));


}

int lower(int c){
    return ((c >= 'A' && c <= 'Z'?( c + 'a' - 'A') : c));
}
