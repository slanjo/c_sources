#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
//this program will search through an input array for matching brackets, parens, and

//Structure defines our stack and our postion on the stack
typedef struct{
    char stack_item[SIZE];//stack element (array element)
    int top; //postion in stack (index)
}Stack;

void push(Stack *, char);
char pop(Stack *);
int isEmpty(Stack *);
char stacktop(Stack *); //returns the character currently top of the stack
int isOpeningMatch(char, char); //left = opening bracket, right = closing bracket element
int checkExpr(char[]); //returns 0 or 1 depending on the validity of expresion under testing

int main(){
    char expr[SIZE];
    printf("Enter the expression: ");
    scanf("%s", expr);
    if (checkExpr(expr)){
        printf("Illegal brackets\n");
    }
    else{
        printf("Good!");
    }
    return 0;
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
    if (isEmpty(s)) {
        printf("Stack is empty");
        exit(1);
    }
    return s->stack_item[s->top];
}
int isOpeningMatch(char left, char right){
    int match = 0;
    switch(left){
        case '(': if (right == ')')
                    match = 1;
                break;
        case '{': if (right == '}')
                    match = 1;
                break;
        case '[': if (right == ']')
                    match = 1;
                break;
        default: printf("Invalid symbol, terminating\n");
                exit(1);
    } 
    return match;
   }

int checkExpr(char expr[]){
    Stack stack;
    stack.top = -1;
    int error = 0;
    int i = 0;
    while (expr[i] != '\0'){
        char next_char = expr[i];
        if (next_char == '(' || next_char == '{' || next_char == '[')
            push(&stack, next_char);
        else if (next_char == ')' || next_char == '}' || next_char == ']')
        {
            if (isEmpty(&stack)){
                error = 1;
                break;
            }
            else if (isOpeningMatch(stacktop(&stack), next_char))
                break;
            else
                error = 1;
        }
        ++i;
    }
    if (!error && !isEmpty(&stack))
        error = 1;
    return error;
}