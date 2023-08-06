#include "evaluation.h"

int evaluate_bin_expr(int lhs, int rhs, char operator)
{
    switch (operator)
    {
    case '+':
        return lhs + rhs;

    case '-':
        return lhs - rhs;

    case '*':
        return lhs * rhs;

    default:
        return 0;
    }
}

void push_stack(int_stack *current_stack, int new_int)
{
    if (current_stack->elem_count < STACK_LEN)
    {
        current_stack->arr[current_stack->elem_count++] = new_int;
    }
}

int pop_stack(int_stack *current_stack)
{
    if (current_stack->elem_count > 0)
    {
        return current_stack->arr[current_stack->elem_count-- - 1];
    }

    return 0;
}