
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack is Full\n");
    } else {
        s->items[++(s->top)] = item;
        printf("The Item successfully added into the stack.....\n");
    }
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty\n");
    } else {
        printf("%d is popped\n", s->items[(s->top)--]);
    }
}

void print(Stack* s) {
    for (int i = 0; i <= s->top; i++) {
        printf("    %d\n", s->items[i]);
    }
    int free = (MAX - s->top - 1);
    double freeper = (free / (double)MAX) * 100;
    printf("Free Space Percentage: %.2f\n", freeper);
}

int main() {
    Stack st;
    initStack(&st);
    int item = 0, choice;

    while(1) {
        printf("\n-----------MENU------------\n");
        printf("1.PUSH operation\n");
        printf("2.POP operation\n");
        printf("3.DISPLAY the Status of the Stack\n");
        printf("----------------------------\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter an element to push: ");
                scanf("%d", &item);
                push(&st, item);
                break;
            case 2:
                pop(&st);
                break;
            case 3:
                printf("The Stack :\n");
                print(&st);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}
