#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "evaluation.h"

int main(void)
{
    int_stack arguments = {{}, 0};

    int current_arg;
    char current_op;

    printf("Enter expression in Reverse Polish Notation, with all operands and operators separated by a whitespace:\n");

    if (scanf("%d", &current_arg) == 1)
    {
        push_stack(&arguments, current_arg);
    }
    else
    {
        return 0;
    }

    while (1)
    {
        scanf("%c", &current_op);

        if (current_op == '\n')
        {
            break;
        }

        if (scanf("%d\n", &current_arg) == 1)
        {
            push_stack(&arguments, current_arg);
        }
        else
        {
            break;
        }

        scanf("%c", &current_op);

        if (current_op == '\n')
        {
            break;
        }
        else if (current_op == ' ' || current_op == '\t')
        {
            scanf("%c", &current_op);
        }

        int rhs = pop_stack(&arguments);
        int lhs = pop_stack(&arguments);

        printf("%d%c%d%c", lhs, current_op, rhs, '=');

        int res = evaluate_bin_expr(lhs, rhs, current_op);
        printf("%d\n", res);

        // int res = evaluate_bin_expr(pop_stack(&arguments), pop_stack(&arguments), current_op);
        push_stack(&arguments, res);
    }

    printf("%s%d\n", "The final result is ", pop_stack(&arguments));

    return 0;
}