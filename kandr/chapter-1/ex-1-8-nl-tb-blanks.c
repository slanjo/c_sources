#include <stdio.h>

//count newlines, tabs, and blanks


int main()
{
    int nl, tb, bl, counter;
    nl = tb = bl = counter = 0;
    while((counter = getchar()) != EOF){
        if (counter == '\n'){
            ++nl;
            printf("newlines=%i\n", nl);
        }
        if (counter == '\t'){
            ++tb;
            printf("tabs=%i\n", tb);
        } 
        if (counter ==  ' '){
            ++bl;
            printf("spaces=%i\n", bl);
    }
     
}

}
