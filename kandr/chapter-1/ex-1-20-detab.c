#include <stdio.h>
#define MAXLINE 1000        //maximum input line size 
//this program checks which line is the longest
//because extern __ssize_t getline (char **__restrict __lineptr,
//                  size_t *__restrict __n,
//                  FILE *__restrict __stream) __wur; is defined in stdio.h
//          we've renamed the function to getlinee
int getlinee(char line[], int maxline);
void copy(char to[], char from []);


int main()
{
    int len;                //current line lenght
    int max;                //maximum length seen so far
    char line[MAXLINE];     //current input line
    char longest[MAXLINE];  //lognest line saved here

    max = 0;
    while ((len = getlinee (line, MAXLINE)) > 0){
        if (len > max) {
                max  = len;
                copy(longest, line);
        }
    }
    if (max > 0)     //there was a line 
        printf("%s", longest);
    return 0;
}

// getlinee: read a line into s, return length 

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
// copy: copy 'from' into 'to'; assuming to is big enough
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != 0)
        ++i;
}

