//Sun May 30 13:57:12 UTC 2021
//Find how many passwords are valid under the rules below
//1-3 a: abcde = VALID 
//2-9 c: ccccccc = INVALID
//1-3 b: cdefg = INVALID
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define YEAR 2020
int load_stack(char[], int);
int count_lines(char[]);

typedef struct record {
//    char *plcy;
    int min;
    char dash;
    int max;
    char letr;
    char scol;
    char pass[20];  
}pass_rcrd; 

int main(){
    int arr_size, result = 0;
    printf("%i\n", arr_size = count_lines("/home/admin/Programming/c_sources/aoc/d2.txt"));
    int expense_elements[arr_size];
    printf("%i\n", result = load_stack("/home/admin/Programming/c_sources/aoc/d2.txt",\
              arr_size));
    printf("%i is the number of newlines\n", arr_size);
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
//create a structure to hold the password records    
    struct record *s = malloc(sizeof(struct record));
   //Initialize struct with data
    while ( fscanf(fps, "%i %c %i %c %c %s", &s->min, &s->dash, &s->max,\
               &s->letr, &s->scol, &s->pass) ==  6 ) {

            if ((( s->letr == s->pass[s->min - 1]) || (s->letr ==\
                            s->pass[s->max -1])) &&\
                    ( s->pass[s->min - 1] != s->pass[s->max - 1] )){
                k++;
            printf("%i%c%i %c%c %s\n", s->min, s->dash, s->max,\
               s->letr, s->scol, &s->pass);
            }
        }


    
//%20[^\n]
    fclose(fps);
    free(s);
    return k;
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

