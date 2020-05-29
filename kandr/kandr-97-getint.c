#include <stdio.h>
#include <ctype.h>
#include <string.h>

int getint(int  *cur_elem){
	printf("this is the string from within getint(): %s\n",  cur_elem);


};



int main(int argc, char *argv[]){
	char s[] = "";
	int SIZE = 10;
	int  array[SIZE]; 
	int n , i, getint(int *);
	
	if (argc != 2){
		fprintf(stderr, "Usage - kandr-97-getint <STRING>\n");
	  	return 1;
	}
	printf("tHis is the string: %s\n",  argv[1]);
	printf("Size of sizeof: %i\n", sizeof( argv[1]));
	array[SIZE] = argv[1];
	printf("This is the string from array array: %10s\n", array[SIZE]);	
	for (n = 0; n < SIZE && getint(&array[n]) != EOF ; n++){
	};
//why is sizeof(argv[1]) = 1? sizeof(argv[1]) is 8 which is correct
/*	for (i = 0; i < strlen( argv[1]); i++){
		printf("sizeof argv[1]: %i\n", strlen(argv[1]));
		printf("Entereed the for loop: %i\n", i);
	};	      
*/	




	return 0;

}
