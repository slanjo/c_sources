#include <stdio.h>
#include <limits.h>
#include <float.h>
//****************HFC*****PAGE 164 DETERMINE THE SIZE OF DATA TYPES**********
//if we want to capture CLI input
//int main(int argc, char *argv[]){
int main(){

	printf("The value of INT_MAX is %i\n", INT_MAX);
	printf("The value of INT_MIN is %i\n", INT_MIN);
	printf("An int takes %i bytes\n", sizeof(int));
	printf("The value of FLT_MAX is %f\n", FLT_MAX);
	printf("The value of INT_MIN is %.50f\n", FLT_MIN);
	printf("A float takes %i bytes\n", sizeof(float));



	return 0;

}
