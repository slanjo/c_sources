#include "hfc_encrypt.h"
//if we want to capture CLI input
//int main(int argc, char *argv[]){
void encrypt(char *message)
{ 
	char c;
	while (*message) {
		*message = *message ^ 31;
		message++;
	}

}
