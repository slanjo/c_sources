//Sun Feb 21 03:34:34 UTC 2021
//Write a program to convert decimal to binary  

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack_item; //pointer to array of stack values for dynamic allocation by malloc
    int top;
    int size;
}Stack;

void printBinary(unsigned int n);
void stackInitMalloc(Stack *, int );
void freeMallocMem(Stack *);
void push(Stack *, int );
int pop(Stack *);
int getSize(Stack *);
int isOverflow(Stack *);
int isUnderflow(Stack *);

int main(){

    printBinary(128); 

    return 0;
}

void push(Stack *s, int value){
    
//    if ( s->top == s->size - 1 ){
//        printf("Stack Overflow \n");
//        return;
        if (isOverflow(s)){
        int *temp;
        temp = (int *) malloc(sizeof(int) * s->size * 2);
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

int pop(Stack *s ){

//     if (s->top == -1){
    if (isUnderflow(s)){
        printf("Stack Underflow\n");
        return -9999;
        }
    int v = s->stack_item[s->top];
    s->top--; 
    return v;
}
void stackInitMalloc(Stack *s, int size){
    
    s->top = -1;
    s->stack_item = (int *) malloc(sizeof(int) * size);
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
