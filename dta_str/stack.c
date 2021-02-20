#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    int top;
    int stck_item[SIZE];
}Stack;

void stack_init(Stack *);
void push(Stack *, int);
int pop(Stack *);

int main(){

    Stack s1, s2;
    stack_init(&s1);
    stack_init(&s2);
    int selection, value;
/*
    push(&s1, 100); 
    push(&s1, 200); 
    push(&s2, 10); 
    push(&s2, 20); 
    push(&s2, 610); 
    printf("Popped from s1 %d\n", pop(&s1));
    printf("Popped from s1 %d\n", pop(&s1));
    printf("Popped from s1 %d\n", pop(&s1));
    printf("Popped from s2 %d\n", pop(&s2));
*/
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Exit\n");
    while(1){
        printf("Enter Selection: \n");
        scanf("%d", &selection);
        switch (selection){
            case 1:
                printf("Enter value to push to the\
top of the stack\n");
                scanf("%d", &value);
                push(&s1, value);
                break;
            case 2:
                if ((value = pop(&s1)) !=  -9999){
                    printf("Popped value = %i\n", value);
                    };
                break;
            case 3: exit(0);
            default: printf("Invalid selection: \n"); 
        }
    }

    return 0;
}

void push(Stack *s, int value){
    
    if (s->top == SIZE - 1){
        printf("Stack Overflow \n");
        return;
    };
    s->top++;
    s->stck_item[s->top] = value;
} 

int pop(Stack *s){
    if (s->top == -1){
        printf("Stack Underflow\n");
        return -9999;
        }
    int v = s->stck_item[s->top];
    s->top--; 
    return v;
}

void stack_init(Stack *s){
    
    s->top = -1;
    return;
    }

 
/*
 
1. PROCEDURE PUSH (v)
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
