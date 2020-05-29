#include <stdio.h>
#include <ctype.h>
#include <string.h>
//Pasing a string into function:
//


void fortune_cookie(char msg[] ){
	printf("Our array inside the function: %s\n",  msg  );
	printf("The address of the first element in the array in the function: %p\n", &msg[0]);
printf("The address of the first element in the array in the function: %p\n", &msg[0]);
printf("The address of the first element in the array in the function: %p\n", &msg[1]);
printf("The address of the first element in the array in the function: %p\n", &msg[2]);
printf("The address of the first element in the array in the function: %p\n", &msg[3]);
printf("The address of the first element in the array in the function: %p\n", &msg[14]);
printf("The address of the first element in the array in the function: %p\n", &msg[15]);
printf("The address of the first element in the array in the function: %p\n", &msg[16]);
printf("The value of the last element in the array is: %c\n", msg[14]);
printf("The value of the last element in the array is: \"%c\"\n", msg[15]);
}

//if we want to capture CLI input
//int main(int argc, char *argv[]){
int main(){
	printf("the size of int is: %i\n", sizeof(double));
	char array[] = "You will be fat";
	printf("The address of array[] is %p\n", &array);
	fortune_cookie(array);
	

	//s = "abc";
	char st[] = "abc";
	//printf("S = %s\n", s);
	printf("st = %s\n", st);







	return 0;

}
