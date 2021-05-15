//Sat Mar 20 19:02:20 AWST 2021
#include "cmpr-headers.h"
#define MAXLEN 1000    /* max length of any input line */

/*readlines: read input lines */

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0; 
    while ((len = getlinee(line, MAXLEN)) > 0){
        if (nlines >= maxlines || (p = alloc(len)) == NULL )
            return -1;
        else {
            line[len - 1] = '\0'; /* delete newline */ 
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
    }
}
/* writelines: write output lines */

void writelines(char *lineptr[], int nlines){
    int i;

//    for (i = 0; i < nlines; i++)
//        printf("%s\n", lineptr[i]);
    while(nlines-- > 0)
        printf ("%s\n", *lineptr++);
}
