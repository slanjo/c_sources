/* Card Evaluation program

 */

#include <stdio.h>
#include <stdlib.h>



int main() {



	char card_name[3];
	int count = 0;
	while( card_name[0] != 'X') {
		puts("Enter the card name: ");
		scanf("%2s", card_name);
		int val = 0;

/*
		if (card_name[0] == 'K') {
			val = 10;
			}
		else if (card_name[0] == 'Q') {
			val = 10;
	
			}
		else if (card_name[0] == 'J') {
			val = 10;
	
			}
		else if (card_name[0] == 'A') {
			val = 11;
	
			}
		else {
			val = atoi(card_name);

			}
		printf("The card value is: %i\n", val);
*/

		switch(card_name[0]) { 
			case 'K':
			case 'Q':
			case 'J':
				val = 10;
				break;
			case 'A':
				val = 11;
				break;
			case 'X':
				continue;
			default:
				val = atoi(card_name);
				if ((val < 1) || (val >10)) {
					printf("Card values can be between 1-10, or one of K,Q,J,A\n");
					continue;
				}

			}




		/*  Check if the falue is 3 to 6 */
		if ((val >= 3) && (val <= 6)) {
			count++;
			puts("Count has gone up");
			}		
		/* Otherwise check if the card was 10, J, Q, or K */
		else if (val == 10) {
			count--;	
			puts("Count has gone down");
			}
	
		printf("Current count is: %i\n", count);	
	}
	return 0;

	
}
 


