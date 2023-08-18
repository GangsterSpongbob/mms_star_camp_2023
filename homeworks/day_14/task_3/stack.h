#ifndef STACK_H
#define STACK_H

#define MAX_ARR_LEN 128

#define CHAR 0
#define INT 1
#define DOUBLE 2
#define STRING 3

typedef struct Stack
{
    void *st_arr[MAX_ARR_LEN];
    unsigned int last_pos;
    char type;
} stack;

stack init_stack(char);

void push_to_stack(void *, stack *);
void *pop_from_stack(stack *);

void print_stack(stack *);

void print_char_stack(stack *);
void print_int_stack(stack *);
void print_couble_stack(stack *);
void print_string_stack(stack *);

#endif // STACK_H