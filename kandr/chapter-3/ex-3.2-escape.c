//Fri 31 Jul 2020 05:30:16 AM AWST
//Write a function escape(s, t) that converts newlines and tabs into visible escape 
//sequence like \n and \t. Use a switch. Write a function for the other direction epacse(s, t)
#include <stdio.h>
#define ARR_SIZE 100
void escape(char s[], char t[]);
void epacse(char s[], char t[]);
int main(){
    char s[100];

//    char s[] = "abc def     fasf		da      "; 
    char u[100];
    char t[ARR_SIZE];
    int k = 0;

    while((s[k] = getchar()) != EOF){   
        k++;
    }
    s[k+1] = '\0'; 
//    scanf("%s", u);
//    printf("string s is: %s\n", s);
    escape(s, t);
    printf("string s after ESCAPE loop: %s\n", s);
    for (k = 0; k < 100; k++)
        t[k] = 0;
    epacse(s, t);
    return 0;
}
void escape(char s[], char t[]){
//    printf("string s is: %s\n", s);
    int i, j;
    j = 0; 
    for (i = 0; i < 100  ; i++){
        switch (s[i]) {
            case '\n':
                t[j] = '\\';
                t[j+1] = 'n';
                j+=2;
                break;
            case '\t':{
                t[j] = '\\';
                t[j+1] = 't';
//                printf("T[i]: %c%c\n", t[i],t[i+1]);
                j+=2;
                break;      }
            default: 
                t[j] = s[i];
                j++;     
                break;
        }
    }
    printf("string t in escape is: %s\n", t); 
}
void epacse(char s[], char t[]){
    int i, j;
    j = 0;
    for (i = 0; i < 100; i++){
        if (s[i] == '\\'){
        switch (s[i+1]) {
            case 't':
                t[j] = '\t';
                i++;
                j++;
                break;
            case 'n':{
                t[j] = '\n';
                i++;
                j++;
                break;      }
            default: 
                t[j] = s[i];
                j++;     
                break;
            }
        }
        else{
            t[j] = s[i];
            j++;
        }
    }
    printf("string t epacse is: %s\n", t);
}
