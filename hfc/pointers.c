#include <stdio.h>
#include <ctype.h>
#include <string.h>

//if we want to capture CLI input
//int main(int argc, char *argv[]){
int main(){
	int y = 10;
	int  i = 4;
	int *pt = &i;
	printf("The address of i is: %p\n", &i);
	printf("The value of i is: %i\n",  *pt);
	pt = &y;
	printf("The value stored in pt after pt = &x %i\n", *pt);	
	int z;
	int *pt2 = &z;
	*pt2 = 33333;
	printf("The value stored in pt2 %i\n", *pt2);
	printf("The address pt2 %p\n",  pt2);
	printf("The value stored in z %i\n", z);
	printf("The address of z = %p\n", &z);
	int x = *pt;
	printf("The value of x is: %i\n",  *pt);
	printf("The addrss of x is: %p\n", &x);
	printf("Changing the value of X through *pt by \"*pt = 10\"\n");	
	*pt = 10;	
	printf("The address of i is: %p\n", &i);
	printf("The value of i is: %i\n",  *pt);
	printf("The value of x is still: %i\n", x);
	x = *pt;
	printf("After doing x = *pt again, the value of x is now: %i\n", x); 
	return 0;

}
