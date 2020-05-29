#include <stdio.h>
#include <ctype.h>
#include <string.h>
//PAGE 124
//if we want to capture CLI input
//int main(int argc, char *argv[]){
int main()
{

	char word[10];
	int i = 0;
	while (scanf("9%s", word) == 1){
	       i = i + 1;
	       if (i % 2)
	        fprintf(stdout, "%s\n", word);
	       else
		fprintf(stderr, "%s\n", word);
	
	}



	return 0;

}
