#ifndef STACK_H
#define STACK_H

#include "generic.h"

struct stack {
    union generic* arr;
    int top;
};

void push(struct stack* stack, union generic value);
union generic top(struct stack* stack);
void pop(struct stack* stack);
int empty(struct stack* stack);
struct stack* createStack(int size);

#endif