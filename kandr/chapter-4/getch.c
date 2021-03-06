//getch.c page 79 getch && ungetch
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define BUFSIZE 100

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0;     // next free position in buf

int getch(void){ // get a (possibly pushed back) character
	return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c){	// push the character back on input
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
