#include <stdio.h>
#include <ctype.h>
#include <string.h>

//if we want to capture CLI input
//int main(int argc, char *argv[]){
//*********This code examines why creating an array with an array variable causes segmentation error and 
//*********why creating one with a new array works
//  *cards is a pointer to a string that the program creates in constants section of memory so we cannot 
//  write to it. 
//  char cards[] = "JFK" basically copies the const onto the stack and then we can change the array. We're never
//  changning the original const. 
//  NEVER CODE as: char *cards = "JFK"; ---meaning never set a char pointer to a string literal
//

int main(){

//	char *cards = "JFK";
	char cards[] = "JFK";
	char a_card = cards[2];
	cards[2] = cards[1];
	cards[1] = cards[0];
	cards[0] = cards[2];
	cards[2] = cards[1];
	cards[1] = a_card;
	puts(cards);


	return 0;

}
