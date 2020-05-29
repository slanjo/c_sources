#include <stdio.h>
#include <ctype.h>
#include <string.h>
//***********HEAD FIRST C - ENUMS***********page 256
//if we want to capture CLI input
//int main(int argc, char *argv[]){
	typedef enum {
		COUNT, POUNDS, PINTS
	
	} units_of_measure;

	typedef union {
		short count;
		float weight;
		float volume;
	} quantity;
	
	typedef struct {
		const char *name;
		const char *country;
		quantity amount;
		units_of_measure units;
	
	} fruit_order;

void display(fruit_order order){
	printf("This order contains ");
	if (order.units == PINTS) //question 1 
		printf("%2.2f pints of %s\n", order.amount.volume, order.name);//question 2
	else if (order.units == POUNDS)
		printf("%2.2f lbs of %s\n", order.amount.weight, order.name);
	else
		printf("%i %s\n", order.amount.count, order.name);
}

int main(){
	fruit_order apples = {"apples", "England", .amount.count = 144, COUNT};
	fruit_order strawberries = {"strawberries", "Spain", .amount.weight = 17.6, POUNDS};
	fruit_order oj = {"orange juice", "U.S.A.", .amount.volume = 10.6, PINTS};

	display(apples);
	display(strawberries);
	display(oj);

	return 0;

}
