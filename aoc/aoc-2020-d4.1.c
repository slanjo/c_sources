//Sun May 23 07:25:00 UTC 2021
//Find the three entries into expens report that sum to 
//2020 and then multiply the three numbers together
//input format: 16-17 w: wwwhwwwwwwwwwwwwq
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define YEAR 2020
int load_stack(char[], int);
int count_lines(char[]);
bool TestForBlankLine(const char * ); 
typedef struct passport {
    char byr;
    char iyr;
    char eyr;
    char hgt;
    char hcl;
    char ecl;
    char pid;
    char cid;;  
}pass_rcrd; 

int main(){
    int arr_size, result = 0;
//    printf("%i\n", arr_size = count_lines("/home/admin/Programming/c_sources/aoc/d4-test-in.txt"));
    printf("%i\n", arr_size = count_lines("C:\\Users\\slaan\\source\\c_sources\\aoc\\d4-test-in.txt"));
    int expense_elements[arr_size];
//    printf("%i\n", result = load_stack("/home/admin/Programming/c_sources/aoc/d4-test-in.txt",\
              arr_size));
    printf("%i\n", result = load_stack("C:\\Users\\slaan\\source\\c_sources\\aoc\\d4-test-in.txt", arr_size));
}
bool TestForBlankLine(const char * line) {
    int i;
    for (i = 0; line[i] != '\0'; i++){
        if (!isspace(line[i]))
                return false;
        return true;
        }
}
int load_stack(char in_data[], int arr_size){
    FILE *fps; 
    int i, j = 0, k = 0, n = 0;
    char c;
    fps = fopen(in_data, "r");
    if(fps == NULL){
        printf("error opening the file %s\n", in_data);
        return 0;
    }
//create a structure to hold the passport record 
    struct passport *s = malloc(sizeof(struct passport));
//Initialize struct with data
//    while ( fscanf(fps, "%i %c %i %c %c %s", &s->min, &s->dash, &s->max,\
//               &s->letr, &s->scol, &s->pass) ==  6 ) {
//        printf("%i %c %i %c%c %s\n", s->min, s->dash, s->max,\
//               s->letr, s->scol, s->pass);
//        for (i = 0; i <= strlen(s->pass); i++){
//            if (s->pass[i] == s->letr)
//                k++;
//        }
//        printf("k = %i\n", k);
//        if (( s->min <= k ) && ( k <= s->max )) 
//            n++;
//        i, k = 0;
//}
    
//%20[^\n]
    fclose(fps);
    free(s);
    return n;
}

int count_lines(char s[]){
//---Count lines in the input files to determine the size of the array
    FILE *fps; 
    int c, n = 0;
    fps = fopen(s, "r");
    if(fps == NULL){
        printf("error opening the file %s\n", s);
        return 0;
    }
   while ((c = (fgetc(fps))) != EOF){
        if (c == '\n')
            ++n;
//        printf("%c", c);            
    }
   fclose(fps);
   return n;
}

