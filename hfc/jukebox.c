#include <stdio.h>
#include <string.h>
//PAGE 84 head first C
//if we want to capture CLI input
//int main(int argc, char *argv[]){
char tracks[][80] = {
	"I left my heart in Harvard Med School",
	"Newark, Newark - a wonderful town",
	"Dancing with a Dork",
	"From here to maternity",
	"The girl from Iwo Jima"
};

void find_track(char search_for[]){

	for (int i = 0 ; i <= 4 ; i++){
		if   (strstr(tracks[i], search_for))  
			printf("The track you're looking for is:%i %s\n", i, tracks[i]);
		
		}		


};



int main(){
	char text[80];
	int i;

	printf("enter the text you're looking for:\n");
	scanf("%79s", &text);
	find_track(text);
	printf(">>>>: %s\n",   text);

	
	return 0;

}
