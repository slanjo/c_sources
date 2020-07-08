#include <stdio.h>
//this program creates a histogram of length of input words
//every 2 words == '-'
#define OUT 0
#define IN 1

int main()
{
    int c, i, k,  nl, nw, nc, state, len_word, c_in_word;
    int word_array[9];

    state = OUT;
    nl = nw = nc = len_word = c_in_word = 0;
    for (i = 0; i < 10; ++i)
        word_array[i] = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
//        if (c == '\n'){
//            c_in_word = 0;
//            ++nl;
//        }
        if (c == ' ' || c == '\t' || c == '\n'){
            c_in_word = 0;
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
            ++len_word;
            ++c_in_word;

        }
        else if (state == IN) {
            ++len_word;
            ++c_in_word;

        }
        if ((state == OUT && len_word > 0)){
            ++word_array[len_word];
            c_in_word = 0;
            len_word = 0;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
    for (i = 1; i < 10; ++i){
        printf("The number of %d letter words is %d\n", i, word_array[i]);
    }
    for (i = 1; i < 10; ++i){
        printf("%d +", i);
        if (word_array[i] == 0)
            ;
        else
        {
            for(k = 1; k <= word_array[i]; ++k)
                printf("-");
        }
        printf("\n");
    } 
}
