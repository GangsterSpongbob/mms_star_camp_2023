#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

stack init_stack(char type)
{
    if (type < CHAR || type > STRING)
    {
        type = CHAR;
    }

    stack new_stack = {{}, 0, type};

    return new_stack;
}

void push_to_stack(void *new_element, stack *cur_stack)
{
    if (cur_stack->last_pos >= MAX_ARR_LEN - 1)
    {
        printf("Cannot push any more elements to stack\n");
        return;
    }

    cur_stack->st_arr[cur_stack->last_pos++] = new_element;
}

void *pop_from_stack(stack *cur_stack)
{
    if (cur_stack->last_pos == 0)
    {
        printf("Cannot pop from empty stack. Returning NULL\n");
        return NULL;
    }

    return cur_stack->st_arr[cur_stack->last_pos--];
}

void print_char_stack(stack *cur_stack)
{
    if (cur_stack->type != CHAR)
    {
        perror("Error while printing\n");
        exit(-1);
    }

    for (size_t i = 0; i <= cur_stack->last_pos; i++)
    {
        printf("%c ", *(char *)(cur_stack->st_arr[i]));
    }
    printf("\n");
}

void print_int_stack(stack *cur_stack)
{
    if (cur_stack->type != INT)
    {
        perror("Error while printing\n");
        exit(-1);
    }

    for (size_t i = 0; i <= cur_stack->last_pos; i++)
    {
        printf("%d ", *(int *)(cur_stack->st_arr[i]));
    }
    printf("\n");
}

void print_double_stack(stack *cur_stack)
{
    if (cur_stack->type != DOUBLE)
    {
        perror("Error while printing\n");
        exit(-1);
    }

    for (size_t i = 0; i <= cur_stack->last_pos; i++)
    {
        printf("%.4lf ", *(double *)(cur_stack->st_arr[i]));
    }
    printf("\n");
}

void print_string_stack(stack *cur_stack)
{
    if (cur_stack->type != STRING)
    {
        perror("Error while printing\n");
        exit(-1);
    }

    for (size_t i = 0; i <= cur_stack->last_pos; i++)
    {
        printf("%s ", (char *)(cur_stack->st_arr[i]));
    }
    printf("\n");
}

void print_stack(stack *cur_stack)
{
    switch (cur_stack->type)
    {
    case CHAR:
        print_char_stack(cur_stack);
        break;

    case INT:
        print_int_stack(cur_stack);
        break;

    case DOUBLE:
        print_double_stack(cur_stack);
        break;

    case STRING:
        print_string_stack(cur_stack);
        break;

    default:
        break;
    }
}