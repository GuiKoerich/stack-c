#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct Stack *_stack;

struct Stack* allocMemory() {
    return (Stack*)malloc(sizeof(Stack));
}

void freeMemory() {
    _stack->top = NULL;
    free(_stack);
}

struct Item* allocItemMemory() {
    return (Item*)malloc(sizeof(Item));
}

void freeItemMemory(struct Item *item) {
    item->next = NULL;
    free(item);
}

int fullMemory(struct Item *item) {
    return item == NULL;
}

void newStack() {
    _stack = allocMemory();
    _stack->top = NULL;
    _stack->length = 0;
}

int isEmpty() {
    return _stack->top == NULL;
}

int stackLength() {
    return _stack->length;
}

int push(int value) {
    Item *item = allocItemMemory();

    if(!fullMemory(item)) {
        item->value = value;
        item->next = _stack->top;

        _stack->top = item;
        _stack->length++;

        return 1;
    }

    return 0;
}

int pop(int *value) {
    Item *temp = allocItemMemory();

    if(!isEmpty()) {
        temp = _stack->top;

        *value = _stack->top->value;
        _stack->top = _stack->top->next;

        freeItemMemory(temp);

        _stack->length--;

        return 1;
    }

    return 0; 
}

int top(int *value){
    if(!isEmpty()){
        *value = _stack->top->value;

        return 1;
    }

    return 0;
}

void showStack() {
    printf("====== TOP ======\n");

    if(isEmpty()) {
        printf("Stack is empty!\n");

    } else {
        int length = stackLength();

        Item *temp = _stack->top;

        int position = 1;
        for(int cont = length; cont > 0; cont--) {
            printf(" - [%d] -- %d \n", position, temp->value);

            if(temp->next != NULL) {
                temp = temp->next;
            }

            position++;
        }
    }

    printf("====== BASE ======\n");
}

void cleanStack() {
    if(isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        int eliminated = top(&eliminated);
        int ord = 1;

        while(!isEmpty()) {
            pop(&eliminated);

            printf(" -- %dº Eliminated value: %d\n", ord, eliminated);
            ord++;
        }

        printf("Stack is empty!\n");
    }
}