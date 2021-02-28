//Sat Feb 20 07:52:49 UTC 2021
//Write a program to manage a simple stack, that dynamically allocates memory to a one-dim array

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack_item; //pointer to array of stack values for dynamic allocation by malloc
    int top;
    int size;
}Stack;

void stackInitMalloc(Stack *, int );
void freeMallocMem(Stack *);
void push(Stack *, int );
int pop(Stack *);
int getSize(Stack *);

int main(){

    Stack s1, s2;
    stackInitMalloc(&s1, 3);
    stackInitMalloc(&s2, 20);
    int selection, value;
    printf("1. Push\n" );
    printf("2. Pop\n" );
    printf("3. Exit\n" );
    while(1 ){
        printf("Enter Selection: \n");
        scanf("%d", &selection);
        printf("Stack size is %d\n", getSize(&s1));
        switch (selection){
            case 1:
                printf("Enter value to push to the top of the stack\n");
                scanf("%d", &value);
                push(&s1, value);
                break;
            case 2:
                if (( value = pop(&s1)) !=  -9999 ){
                    printf("Popped value = %i\n", value);
                    };
                break;
            case 3: 
                freeMallocMem(&s1);
                exit(0);
            default: printf("Invalid selection: \n"); 
        }
    }

    return 0;
}
//------------------
void push(Stack *s, int value){
    
    if ( s->top == s->size - 1 ){
//        printf("Stack Overflow \n");
//        return;
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

    if ( s->top == -1){
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
/*
1. PROCEDURE PUSH (v )
2. IFTOP=SIZE–1THEN
3. DISPLAY “STACK OVERFLOW”
4. EXIT PUSH
5. END IF
6. TOP:=TOP+1 // INCREMENT THE TOP OF THE STACK BY 1
7. S[TOP]:=v // ASSIGN THE ELEMENT AT THE TOP POSITION OF THE STACK
8. END PROCEDURE PUSH

1. PROCEDURE POP ()
2. IF S.TOP == -1 THEN
3. DISPLAY “STACK UNDERFLOW”
4. EXIT POP
5. END IF
6. v:=S[TOP]
7. TOP:=TOP – 1
8. RETURN v
9. END PROCEDURE POP

*/ 
