#include <stdio.h>


//This shows pointer decay: the main function printf will show the size of the array/string(38 bytes),
//however the fortune cookie printf shows the pointer size - 8 bytes. 
//compiler issues a warning for line 10 becuase of the decay. 
void fortune_cookie(char msg[])
	{

		printf("Passed string is: %s\n", msg);
		printf("The size of the string in bytes = %i \n", sizeof(msg));

	}

int main(){
	char quote[] = "This is a passed string of characters";
	fortune_cookie(quote);
	printf("The size of the quote array is: %i\n",sizeof(quote));
	return 0;


}
