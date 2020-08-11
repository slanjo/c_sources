//Tue 11 Aug 2020 04:02:00 AM AWST
//atof page 71
//convert string s to double
#include <ctype.h>
#include <stdio.h> 
#define MAXLINE 100
double atoff(char s[]){
    double val, power;
    int i, sign, k;
    int exp, sign2;

    for (i = 0; isspace(s[i]); i++) //skip white space
            ;
    sign = (s[i] == '-')? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit (s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    if (s[i] == '-'){
        sign2 = -1;
        i++;
    }
    else if (s[i] == '+'){
        sign2 = 1;
        i++;
    }
    else
        sign2 = 1;
    for (exp = 1; isdigit(s[i]); i++)
        exp = 10 * exp +  (s[i] - '0');
    for (k = 0; k < exp; k++)
        exp *= 10;
    return exp * sign2 * sign * val / power;
}
int main(){
    double sum, atof(char []);
    char line[MAXLINE];
    int getlinee(char line[], int max);

    sum = 0;
    while (getlinee(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atoff(line));
    return 0;
}
int getlinee(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
//        for (i = 0; i < lim-1 && (c = getchar ()) != EOF && c != '\n'; ++i)
//    s[i] = c;
    s[i++] = c;
    if (c == '\n') {
//        s[i] = c;
        s[i++] = c;
//        ++i;
    }
    s[i] = '\0';
    return i;
}
