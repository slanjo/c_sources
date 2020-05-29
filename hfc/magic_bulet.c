#include <stdio.h>



int main() {

	char masked_raider[] = "Alive";
	char *jimmy = masked_raider;
	printf("Masked raider is %s, and Jimmy is %s\n", masked_raider, jimmy);
	printf("The address of &masked_raider[] is: %p\n", &masked_raider[0]);
	printf("The address of masked_raider[] is: %p\n", masked_raider);
	printf("The address of &jimmy is: %p\n",  &jimmy);
	printf("The address of *jimmy is: %p\n", *jimmy);
	printf("The address of jimmy is: %p\n", jimmy );


	masked_raider[0] = 'D';	
	masked_raider[1] = 'E';	
	masked_raider[2] = 'A';	
	masked_raider[3] = 'D';
	masked_raider[4] = '!';
	printf("Masked raider is %s, and Jimmy is %s\n", masked_raider, jimmy);

	
	
	return 0;	


}
