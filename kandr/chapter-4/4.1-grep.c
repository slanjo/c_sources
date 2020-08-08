//Sat 08 Aug 2020 09:24:42 AM AWST
//page 61. a version of "grep" function utilizing hand made getline; that finds
//and prints all lines matching a pattern
#include <stdio.h>
#define MAXLINE 1000             // maximum input line length
int getlinee(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould";        //pattern we're searching for
int main(){
    char line[MAXLINE];
    int found = 0;

    while (getlinee(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0){
            printf("%s", line);
            found ++;
        }
    return found;
}
int getlinee(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar ()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
 }
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
