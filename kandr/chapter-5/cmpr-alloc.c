#include "cmpr-headers.h"
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
   if (allocbuf + ALLOCSIZE - allocp >= n){ //Test if there is enogh space for requested storage
      allocp += n;
     return allocp - n;
   }
   else 
      return 0;
} 

void  afree(char *p){
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

