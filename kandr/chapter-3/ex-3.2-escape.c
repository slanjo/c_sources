//Fri 31 Jul 2020 05:30:16 AM AWST
//Write a function escape(s, t) that converts newlines and tabs into visible escape 
//sequence like \n and \t. Use a switch. Write a function for the other direction epacse(s, t)
//
#include <stdio.h>
#define ARR_SIZE 100
void escape(char s[], char t[]);
int main(){
    char s[] = "abc def     fasfda"; 
    char t[ARR_SIZE];
    int k = 0;

    while(!EOF){   
        s[k] = getchar();
        k++;
    } 
//    scanf("%s", s);
    printf("string s is: %s\n", s);
   
    escape(s, t);
    return 0;
}

void escape(char s[], char t[]){
    printf("string is: %s\n", s);
    int i, k;
    for (i = 0; i < 100; i++){
        switch (s[i]) {
            case '\t':
                t[i] = 't';
            case '\n':{
                t[i] = '\n';
                printf("T[i]: %c", t[i]);
                      }
            default:
                t[i] = s[i];
        }
    }
    printf("string t is: %s\n", t); 

}

