#include <stdio.h>
#include <ctype.h>
#include <string.h>

//if we want to capture CLI input
//int main(int argc, char *argv[]){

void print_reverse(char  *s){//can be done as void print_reverse(char   s[]); 
	size_t len = strlen(s);
	char *t = s + len - 1;
	while ( t >= s ){
		printf("%c", *t);
		t = t - 1;
	}
	puts("");

}
int main(){

	char *juices[] = {
	"dragonfruit", "waterberry", "sharonfruit", "uglifruit",
	"rumberry", "kiwifruit", "mulberry", "strawberry",
	"blueberry", "blackberry", "starfruit"
	};
	char *a;
	puts(juices[6]);
	print_reverse(juices[7]);
	a = juices[2];
	juices[2] = juices[8];
	juices[8] = a;
	puts(juices[8]);
	puts(juices[2]);
	print_reverse(juices[(18 + 7) / 5]);
	puts(juices[2]);
	print_reverse(juices[9]);
	juices[1] = juices[3];
	puts(juices[10]);
	print_reverse(juices[1]);
	return 0;

}
