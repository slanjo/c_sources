#include <stdio.h>
//HEAD FIRST C **** BERMUDA TOOL **** PAGE 138 ***** 
//if we want to capture CLI input
//int main(int argc, char *argv[]){
int main(){
	float latitude;
	float longitude;
	char info[80];
	while (scanf("%f,%f,%s79[^\n", &latitude, &longitude, info) == 3)
		if (( latitude > 26) && ( latitude < 34))
			if (( longitude > -76) && (longitude < -64))
				printf("%f,%f,%s\n", latitude, longitude, info);
			

	


	return 0;

}
