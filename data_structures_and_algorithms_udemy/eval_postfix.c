//Mon 01 Mar 2021 04:00:36 PM AWST
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100

typedef struct{
    int top;
    double stack_item[SIZE];
}OperandStack;

int isEmpty(OperandStack *);
void push(OperandStack *, double);
char pop(OperandStack *);
double evalPostfix(char[]);
double operate(double, double, char);

int main(){
    char postfix[SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    double result = evalPostfix(postfix);
    printf("%d\n", result);
}

void push(OperandStack *s, double value){
    if (s->top == SIZE - 1){
        printf("OperandStack Overflow Exiting\n");
        exit(1);
    }
    s->stack_item[++s->top] = value; //push the character to the top of the stack
}

char pop(OperandStack *s){
    if (isEmpty(s)) {
        printf("OperandStack Underflow Exiting\n");
        exit(1);
    }
return s->stack_item[s->top--]; 
}

//will return 1 if stack is empty, 0 if not empty
int isEmpty(OperandStack *s){
    return s->top == -1;
}

double evalPostfix(char postfix[]){
    OperandStack stack;
    stack.top = -1;
    int i = 0;
    while(postfix[i] != '\0'){
        char token = postfix[i];
        if ( token >= '0' && token <= '9'){ //s
            int value = token - '0'; // convert char to int
            push(&stack, (double)value);
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '$'){
            double opnd1 = (double) pop(&stack);
            double opnd2 = (double) pop(&stack);
            double result = operate(opnd2, opnd1, token);
            push(&stack, result);
        }
        else{
            printf("Error-out\n");
            exit(1);
        }
        ++i;
    }
    return pop(&stack);
}

double operate(double leftOpnd, double rightOpnd, char opr){
    double result = 0.0;
    switch(opr){
        case '+': result = leftOpnd + rightOpnd;
            break;
        case '-': result = leftOpnd - rightOpnd;
            break;
        case '*': result = leftOpnd * rightOpnd;
            break;
        case '/': result = leftOpnd / rightOpnd;
            break;
        case '$': result = pow(leftOpnd, rightOpnd);
            break;
        default: printf("%c is not a valid operator\n", opr);
            exit(1);
    }
    return result;
}
