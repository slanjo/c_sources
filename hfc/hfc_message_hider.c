#include <stdio.h>
#include "hfc_encrypt.h"
//if we want to capture CLI input
//int main(int argc, char *argv[]){
int main(){
	char msg[80];
	while (fgets(msg, 80, stdin)) {
		encrypt(msg);
		printf("%s", msg);
	}



	return 0;

}
