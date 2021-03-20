#include <stdio.h>
#include <string.h> 
#include "cmpr-headers.h"
//#include "cmpr-qsort.h"
//#include "cmpr-readlines.h"
#define MAXLINES 5000
char *lineptr[MAXLINES];
/*
int readlines(char *lineptr[], int nlines);
void writelines(char *lienptr[], int nlines);

void qsorts(char *lienptr[], int left, int right);
*/

/* sort input lines */

int main(){
    int nlines; /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsorts(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("error: input too big to sort\n");
        return 1;
    }
}
