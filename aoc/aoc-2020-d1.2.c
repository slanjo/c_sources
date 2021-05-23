//Sat May 22 12:26:31 UTC 2021
//Find the three entries into expens report that sum to 
//2020 and then multiply the three numbers together
#include <stdio.h>
#include <stdlib.h>
#define YEAR 2020
int load_stack(char[], int[], int);
int count_lines(char[]);
typedef struct {
   int *expense;
}Stack; 


int main(){
    int result = 0;
    int arr_size = count_lines("/home/admin/Programming/C/aoc/d1.txt");
    int expense_elements[arr_size];
    printf("%i\n", result = load_stack("/home/admin/Programming/C/aoc/d1.txt",\
              expense_elements, arr_size));
}

int load_stack(char in_data[], int arr[], int arr_size){
    int arra[arr_size];
    FILE *fps; 
    int i, j, k, n = 0;
    char c;
    fps = fopen(in_data, "r");
    if(fps == NULL){
        printf("error opening the file %s\n", in_data);
        return 0;
    }
    Stack s;
   //Initialize array with zeroes. 
    for(i = 0; i < arr_size; i++){
        arra[i] = 0;
    }
    i = 0;
    while ( fscanf(fps, "%i", arra) ==  1 ) {
        arr[i] = arra[0];  
        i++;  }
//[^\n]
    fclose(fps);
    for(i = 0; i < arr_size; i++){
       for (j = i + 1; j < arr_size ; j++){ 
           for (k = j + 1; k < arr_size; k++){
                if (arr[i] + arr[j] + arr[k] == YEAR){
                    return arr[i] * arr[j] * arr[k];
                    break;
           }
           }
       }
    }
    return n;

}

int count_lines(char s[]){
//---Count lines in the input files to determine the size of the array
    FILE *fps; 
    int c, n1 = 0;
    fps = fopen(s, "r");
    if(fps == NULL){
        printf("error opening the file %s\n", s);
        return 0;
    }
   while ((c = (fgetc(fps))) != EOF){
        if (c == '\n')
            ++n1;
//        printf("%c", c);            
    }
   fclose(fps);
   return n1;
}

