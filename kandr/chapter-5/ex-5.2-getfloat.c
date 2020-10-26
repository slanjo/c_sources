//Tue 27 Oct 2020 06:17:53 AM AWST
//get a float from input 
#include <ctype.h>
#include <stdio.h> 
#define MAXLINE 100
double atoff(char []);
int getlinee(char line[], int max);

int main(){
    double sum; 
    char line[MAXLINE];
    sum = 0;
    while (getlinee(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atoff(line));
        printf("atoff + 1000 = %f\n", sum + 1000);
    return 0;
}
int getlinee(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
double atoff(char s[]){
    double val, power, exp1;
    int i, sign, k;
    int exp, n, sign2; //exp = exponent in scientific notation, sign2 - 
    sign2 = 0;                      //sign2 used for expressing exponent value
    exp1 = 1;
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
    if (s[i] == 'e' || s[i] == 'E'){
        i++;
    }
    if (s[i] == '-'){
        sign2 = -1;
        i++;
    }
    if (s[i] == '+'){
        sign2 = 1;
        i++;
    }
    //if there was scientific notation convert it to proper values
    for (exp = 0; isdigit(s[i]); i++)
        exp = 10 * exp +  (s[i] - '0');
    for (k = 1; k <= exp; k++)
        exp1 *=  10.0;
    if (sign2 == -1)
        exp1 = (double) ( 1 / exp1);
    return exp1 *  sign * val / power;
}
