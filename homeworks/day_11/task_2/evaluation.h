#ifndef EVALUATION_H
#define EVALUATION_H

#include <stdint.h>

#define STACK_LEN 32

typedef struct Int_stack
{
    int arr[STACK_LEN];
    uint8_t elem_count;
} int_stack;

void push_stack(int_stack *, int);
int pop_stack(int_stack *);

int evaluate_bin_expr(int, int, char);

#endif // EVALUATION_H