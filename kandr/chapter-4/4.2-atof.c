//Tue 11 Aug 2020 04:02:00 AM AWST
//atof page 71
//convert string s to double
#include <ctype.h>
#include <stdio.h> 
#define MAXLINE 100
double atoff(char s[]){
    double val, power;
    int i, sign, k;
    int scientific;

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
    k = i;
    if ((s[i] == 'e' || s[i] == 'E')) { 
    for (scientific = 0; isdigit(s[i]); i++)
        scientific = 10 * scientific +  (s[i] - '0');

    }
    if (isdigit(s[i]))   
    (s[k++] == '-' || s[k] == '+'))       
    

    return sign * val / power;
}
int main(){
    double sum, atof(char []);
    char line[MAXLINE];
    int getlinee(char(line, MAXLINE) > 0);

    sum = 0;
    while (getlinee(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atoff(line));
    return 0;
}
