#include <stdio.h>
#include <ctype.h>
#include <string.h>

//if we want to capture CLI input
//int main(int argc, char *argv[]){
int main(){

	int a = 100000;
	short b = a;
	printf("b = %hi\n", b);
	int x = 6;
	int y = 7;
	//float  z = x / y;
	float  z = (float)x / (float)y;
	//float  z = (float)6 / (float)7;
	printf("6/7 = %f\n", z);


	return 0;

}
