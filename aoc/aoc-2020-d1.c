//Fri May 21 19:54:41 UTC 2021
//Find the two entries that sum to 2020 and then multiply those two numbers together
#include <stdio.h>
#include <stdlib.h>
int load_stack(char[], int[], int);
int count_lines(char[]);
typedef struct {
   int *expense;
}Stack; 


int main(){
    int result;
    int arr_size = count_lines("/home/admin/Programming/C/aoc/d1.txt");
    int expense_elements[arr_size];
    printf("%i\n", result = load_stack("/home/admin/Programming/C/aoc/d1.txt",\
                expense_elements, arr_size));

}

int load_stack(char in_data[], int arr[], int arr_size){
    int arra[arr_size];
    FILE *f; 
    int i, j, n=0;
    char c;
    f = fopen(in_data, "r");
    if(f == NULL){
        printf("error opening the file %s\n", in_data);
        return 0;
    }
    Stack s;
   //Initialize array with zeroes. 
    for(i = 0; i < arr_size; i++){
        arra[i] = 0;
    }
    i = 0;
    while ( fscanf(f, "%i", arra) ==  1 ) {
        arr[i] = arra[0];  
        i++;  }
//    printf("%i - %i - %i\n", arr[0], arr[1], arr[199]);
//[^\n]
    fclose(f);
    for(i = 0; i < arr_size; i++){
       n = 2020 - arr[i];
       for (j = 0; j < arr_size ; j++){ 
           if (arr[j] == n){
               return n * arr[i];
               break;
           }
       }
    }
    return 0;
}

int count_lines(char s[]){
//---Count lines in the input files to determine the size of the array
    FILE *f; 
    int c, n = 0;
    f = fopen(s, "r");
    if(f == NULL){
        printf("error opening the file %s\n", s);
        return 0;
    }
    while ((c = (fgetc(f))) != EOF){
        if (c == '\n')
            ++n;
    }
    fclose(f);
    return n;
}

