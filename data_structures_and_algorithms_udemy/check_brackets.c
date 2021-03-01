#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
//this program will search through an input array for matching brackets, parens, and
//
//Structure defines our stack and our postion on the stack
typedef struct{
    char stack_item[SIZE];
    int top;
}Stack;

void push(Stack *, char);
char pop(Stack *);
int isEmpty(Stack *);
char stacktop(Stack *);
int isOpeningMatch(char, char);
int checkExpr(char[]);

int main(){

}

void push(Stack *s, char value){
    if (s->top == SIZE - 1){
        printf("Stack Overflow Exiting\n");
        exit(1);
    }
//    s->top++;
//    s->stack_item[s->top] = value; lines 34 and 35 are written as one below
    s->stack_item[++s->top] = value; //push the character to the top of the stack
}
char pop(Stack *s){
    if (isEmpty(s)) {
        printf("Stack Underflow Exiting\n");
        exit(1);
    }
//    value = s->stack_item[s->top];
//    --s->top;
    return s->stack_item[s->top--]; //same as lines 39 && 40
}
int isEmpty(Stack * s){
    return s->top == -1;
    }
char stacktop(Stack *s){
    char next_char;
    if (next_char == '{' || next_char == '(' || next_char == '['){
        push(&s, next_char);

    } 
}