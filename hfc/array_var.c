#include <stdio.h>
#include <ctype.h>
#include <string.h>

//if we want to capture CLI input
//int main(int argc, char *argv[]){
int main(){
	char array[] = {1,2,3,4,5,6,7,8,9};
	int y = array[0];
	int x = *(array+1);
	printf("array[0] is %i, and *(array+1) is %i\n", y, x);	
        printf("we can also print the value first array element by using\n *array\n");
	printf("value of first array again: %i\n", *array);
	return 0;

}
