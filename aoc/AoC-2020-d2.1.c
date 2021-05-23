//Sun May 23 07:25:00 UTC 2021
//Find the three entries into expens report that sum to 
//2020 and then multiply the three numbers together
//input format: 16-17 w: wwwhwwwwwwwwwwwwq

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
    printf("%i\n", arr_size = count_lines("/home/admin/Programming/C/aoc/d2.txt"));
    int expense_elements[arr_size];
    printf("%i\n", result = load_stack("/home/admin/Programming/C/aoc/d2.txt",\
              arr_size));
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
//        printf("%i %c %i %c%c %s\n", s->min, s->dash, s->max,\
//               s->letr, s->scol, s->pass);
        for (i = 0; i <= strlen(s->pass); i++){
            if (s->pass[i] == s->letr)
                k++;
        }
//        printf("k = %i\n", k);
        if (( s->min <= k ) && ( k <= s->max )) 
            n++;
        i, k = 0;
}
    
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

