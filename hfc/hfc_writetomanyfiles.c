#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//******HEAD FIRST C******Page 137 FILES
//if we want to capture CLI input
//int main(int argc, char *argv[]){
int main(int argc, char *argv[])
{
	char line[80];
	if ( argc != 6 ) {
		fprintf(stderr, "You need to provide 5 CLI arguments\n");
		return 1;
	}

//	FILE *in = fopen("spooky.csv", "r");
	FILE *in;
	if (!(in = fopen("spooky.csv", "r"))) {
		fprintf(stderr, "File doesn't exist\n");
		return 1;
	}

	FILE *file1 = fopen(argv[2], "w");
	FILE *file2 = fopen(argv[4], "w");
	FILE *file3 = fopen(argv[5], "w");
	while (fscanf(in, "%s79[^\n]", line) == 1) {
		if (strstr(line, argv[1]))
			fprintf(file1, "%s\n", line);
		else if (strstr(line, argv[3]))
			fprintf(file2, "%s\n", line);
		else 
			fprintf(file3, "%s\n", line);


	}
	fclose(file1);
	fclose(file2);
	fclose(file3);

	return 0;

}
