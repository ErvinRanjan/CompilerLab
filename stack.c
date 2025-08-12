#include "stack.h"
#include <stdlib.h>

struct stack* createStack(int size) {
    struct stack* stack = malloc(sizeof(struct stack));
    stack->arr = malloc(size * sizeof(union generic));
    stack->top = -1;
    return stack;
}

void push(struct stack* stack, union generic value) {
    stack->arr[++(stack->top)] = value;
}

union generic top(struct stack* stack) {
    return stack->arr[stack->top];
}

void pop(struct stack* stack) {
    (stack->top)--;
}

int empty(struct stack* stack) {
    return stack->top == -1;
}