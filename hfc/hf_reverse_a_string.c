#include <stdio.h>
#include <ctype.h>
#include <string.h>

//if we want to capture CLI input
//int main(int argc, char *argv[]){

void print_reverse(char  *s){//can be done as void print_reverse(char   s[]); 
	size_t len = strlen(s);
	printf("%p\n", s  );
	
	char *t = s + len - 1;
	printf("\n");
	char x = *t;
	printf("%c\n",x);
	printf("Memory after moving to the back: %p\n", t);
	printf("string: %s\n", t);
	while ( t >= s ){
		printf("%c---->%p\n", *t, t);
		t = t - 1;
	}
	printf("\n");
	t = s;	
	x = *t;
	printf("%c\n",x);

}
int main(int argc, char argv[]){

	if (argc != 2)
		printf("Usage ./hf_reverse_string <STRING>\n");
	//print_reverse(&argv[2]);
	char array[] = "123456";
	print_reverse(array);

	return 0;

}
