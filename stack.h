#ifndef _STACK_H_
#define _STACK_H_
#include "adt.h"

typedef struct Stack {
    struct Item *top;
    int length;
} Stack;

struct Stack* allocMemory();
void freeMemory();
struct Item* allocItemMemory();
void freeItemMemory(struct Item *item);
int fullMemory(struct Item *item);

void newStack();
int isEmpty();
int stackLength();
int push(int value);
int pop(int *value);
int top(int *value);
void showStack();
void cleanStack();

#endif