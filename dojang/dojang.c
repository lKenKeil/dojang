#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 10

typedef struct {
    int top;
    int data[MAX_STACK_SIZE];
} Stack;

void init_stack(Stack* s) {
    s->top = -1;
}

int is_full(Stack* s) {
    return (s->top == MAX_STACK_SIZE - 1);
}

int is_empty(Stack* s) {
    return (s->top == -1);
}

void push(Stack* s, int item) {
    if (is_full(s)) {
        printf("Stack Full\n");
        return;
    }
    s->data[++(s->top)] = item;
}

int pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack Empty\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int main() {
    Stack s;
    init_stack(&s);
    srand(time(NULL)); 
    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100 + 1;
        if (rand_num % 2 == 0) {
            push(&s, rand_num);
            printf("Push %d\n", rand_num);
        }
        else {
            int popped_num = pop(&s);
            printf("Pop %d\n", popped_num);
        }
    }
    return 0;
}



