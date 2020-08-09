//Sun 09 Aug 2020 04:55:15 PM AWST
//page 61. a version of "grep" function utilizing hand made getline; that finds
//and prints all lines matching a pattern
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000             // maximum input line length
int getlinee(char line[], int max);
int strrindex(char source[], char searchfor[]);
//char pattern[] = "ould";        //pattern we're searching for
char pattern[] = "aaZ"; 
int main(){
    char line[MAXLINE];
    int found = 0;
    int right_most = -1;
    while (getlinee(line, MAXLINE) > 0)
        if (strrindex(line, pattern) >= 0){
            printf("%s", line);
            found ++;
        }
    return found;
}
int getlinee(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
//    for (i = 0; i < lim-1 && (c = getchar ()) != EOF && c != '\n'; ++i)
//        s[i] = c;
        s[i++] = c;
    if (c == '\n') {
//        s[i] = c;
        s[i++] = c;
//        ++i;
    }
    s[i] = '\0';
    return i;
 }
int strrindex(char s[], char t[])
{
    int i, j, k, l, right_most;
    l = 0;
    right_most = 0;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
           l++;
        if ((strlen(t) == (l)) && (k > 0) && (t[k] == '\0')) //check if we found a match of t in s
            right_most = i; //j - strlen(t);
        else 
            l = 0;
//        printf("i%i, j%i, k%i, l%i, right_most%i\n", i, j, k, l, right_most);
//        if (k > 0 && t[k] == '\0'){
//            printf("position: %i\n", right_most);
//            return i;
//        }
    }
    printf("right_most position is: %i\n", right_most);
    return ((right_most > 0) ? right_most : -1);
}
