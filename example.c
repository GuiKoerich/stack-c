#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

void fibonacci(int position) {
    newStack();

    int first = 0;
    int second = 1;

    push(first);
    push(second);

    int next;

    for(int count = 0; count < position; count++) {
        next = first + second;
        first = second;
        second = next;

        push(next);    
    }
}

void main() {
    fibonacci(8);
    showStack();
    printf("\n");
    cleanStack();
}