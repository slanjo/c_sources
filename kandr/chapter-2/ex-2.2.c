//Exercise 2-2 page 42
//Solved by using nested if:
//
for (i = 0; i < lim -1; i++){
    if (c = getchar()) != '\n'{
        if c != EOF
            s[i] = c;
    }
}

//from https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_2:Exercise_2
//using only operands from that chapter
#include <stdio.h>

int main(void) {
        int c, i;

            for (i = 0; ((i < 999) + ((c=getchar()) != EOF) + (c != '\n')) == 3; ++i) {
                        putchar(c);
                            }
}
