//Sat Feb 27 10:16:59 UTC 2021
//Write a program to convert decimal to binary  

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *stack_item; //pointer to array of stack values for dynamic allocation by malloc
    int top;
    int size;
}Stack;

void printBinary(unsigned int n);
void stackInitMalloc(Stack *, int );
void freeMallocMem(Stack *);
void push(Stack *, char);
char pop(Stack *);
int getSize(Stack *);
int isOverflow(Stack *);
int isUnderflow(Stack *);
int reverseIt(char[], char[]);

int main(){

//    printBinary(128); 
    int f = reverseIt("/home/slanjo/Programming/C/dta_str/input_text.txt", "/home/slanjo/Programming/C/dta_str/output_text.txt");
    if (f)
        printf("File copied successfully\n");
    else
        printf("Error -- copy failed\n");
    return 0;
}

void push(Stack *s, char value){
    
//    if ( s->top == s->size - 1 ){
//        printf("Stack Overflow \n");
//        return;
        if (isOverflow(s)){
        char *temp;
        temp = (char *) malloc(sizeof(char) * s->size * 2);
        if ( temp == NULL ){
            printf("Stack Overflow\n");
            return;
        }
        int i;
        for(i=0; i <= s->top; i++){
            temp[i] = s->stack_item[i];
        }
        free(s->stack_item);
        s->stack_item = temp;
        s->size = s->size * 2;
    }
    s->top++;
    s->stack_item[s->top] = value;
} 

char pop(Stack *s ){

//     if (s->top == -1){
    if (isUnderflow(s)){
        printf("Stack Underflow\n");
        return '\0';
        }
    int v = s->stack_item[s->top];
    s->top--; 
    return v;
}
void stackInitMalloc(Stack *s, int size){
    
    s->top = -1;
    s->stack_item = (char *) malloc(sizeof(char) * size);
    if ( s->stack_item == NULL  ){
        printf("Failed to alocate memory\n");
        exit(1);
    }
    s->size = size;
    return;
    }

void freeMallocMem(Stack *s){

    if ( s->stack_item != NULL ){
        free(s->stack_item);
        s->top = -1;
        s->size = 0;
    }
    printf("Freed freeMallocMem \n");
    return;
}

int getSize(Stack *s){
    return  s->size;
}

void printBinary( unsigned int n){
    Stack s;
    int bin;
    printf("The %i in binary is: ", n);
    const int BASE = 2;
    stackInitMalloc(&s, 15);
    while (n > 0){
        bin = n % BASE;
        push(&s, bin);
        n = n / BASE;
    }
//    while (s.top != -1){
    while(!isUnderflow(&s)){
        printf("%d", pop(&s));
                }
    printf("\n");
    freeMallocMem(&s);
    return;
}

int isOverflow(Stack *s){
    return s->top == s->size - 1;
}

int isUnderflow(Stack *s){
    return s->top == -1;
}

int reverseIt(char source[], char dest[]){
    printf("in reverseIt\n");
    int i = 0;
    while(!'\0') {
        printf("%c", source[i]);
        i++;

                }
    FILE *fps, *fpd;
    const int SIZE = 50;
    fps = fopen(source, "r");
    if(fps = NULL){
        printf("Error opening the file %s\n", source);
        return 0;
    }
    fpd = fopen(dest, "r");
    if(fpd == NULL){
        printf("Errof opening the file %s\n", dest);
        return 0;
            }
    Stack s;
    stackInitMalloc(&s, SIZE);
    char buff;
    buff = fgetc(fps);
    while(!feof(fps)){
        push(&s, buff);
        buff = fgetc(fps);
    }
    while(!isUnderflow(&s)){
        fputc(pop(&s), fpd);
    }
    fclose(fps);
    fclose(fpd);
    freeMallocMem(&s);
    return 1;
}
            
