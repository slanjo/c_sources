#include <stdio.h>


int main(){
	int s[] = {1, 2, 3};
	int *a =  s  ;	
	// *a = s;
	printf("adress of array s = %p\n",  s);
	printf("a = : %p\n",  a);
	printf("s = %i\n", s[0]);
	printf("s = %i\n", *a);
	printf("a = %p\n",  a);
	printf("a = %i\n", a);
	return 0;
       	



}
