#include <stdio.h>
#include <ctype.h>
#include <string.h>

//if we want to capture CLI input
//int main(int argc, char *argv[]){
int main(){
	int contestants[] = {1,2,3};
	int *choice = contestants;
	printf("Value of *choice: %i\n", *choice);
	contestants[0] = 2;
	contestants[1] = contestants[2];
	contestants[2] = *choice;
	printf("Picked contestant: %i\n: ;", contestants[2]);



	return 0;

}
