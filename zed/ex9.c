#include <stdio.h>

int main(int argc, char *argv[]){
    int i = 0;

    char *states[] = {"California", "Oregon", "Washington", "Texas"};
    while (i < 25) {
        printf("%d", i);
        i++;
    }

    return 0;
}
