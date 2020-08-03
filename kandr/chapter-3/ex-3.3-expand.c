//Mon 03 Aug 2020 06:51:54 AM AWST
//Exercise 3.3 page 63. Write a function expand(s1, s2) that expands shorthand
//notations like a-z in the string s1 into the equivalent complete list abc...xyz
//in s2. Allow for letters of either case and digits, and be prepared to handle cases
//like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
//literally. 
#include <stdio.h>
#include <string.h>
#define AR_SIZE 100
void expands(char s1[], char s2[]);
int main(){
    char s1[] = "-a-z0-9-";
    char s2[AR_SIZE];
    expands(s1, s2);
}

void expands(char s1[], char s2[]){
    int j = 0;
    char c;
    printf("strlen of s1 is %li\n", strlen(s1));
        for (int i = 0; i < strlen(s1) ; i++){
            if (s1[0] == '-'){
                s2[0] = '-';
            }
            if ((s1[i] == '-') && (s1[i-1] == 'a') && (s1[i+1] == 'z')){
    //            printf("%s", s1 );
                for (j=0, c = ('a' - 0) ; c <= ('z' - 0);  j++, c++ )
                    s2[j] = c;
    //            printf("J is: %i\n", j); 
                s2[j] = '\0';
            }
            else if ((s1[i] == '-') && (s1[i-1] == '0') && (s1[i+1] == '9')){
    //            printf("%s", s1 );
                for ( c = ('0' - 0) ; c <= ('9' - 0); j++, c++ )
                    s2[j] = c;
    //                putchar(c);
    //            printf("J is: %i\n", j); 
            }
            if (s1[strlen(s1) - 1] == '-')
                s2[j] = '-';
            s2[j+1] = '\0';
    }
    printf("S2 is: %s\n", s2);
}
