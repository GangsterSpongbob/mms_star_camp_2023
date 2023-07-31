#include "io_funcs.h"

#include <stdlib.h>
#include <string.h>

#include "arithmetic.h"

uint8_t is_sign(char c)
{
    return c == '+' || c == '*' || c == '^';
}

uint8_t is_numeric(char c)
{
    return c >= '0' && c <= '9';
}

uint8_t count_parentheses(char *str)
{
    int index = 0;
    uint8_t par_counter = 0;
    while (str[index] != '\0')
    {
        if (str[index++] == '(')
        {
            par_counter++;
        }
    }

    return par_counter;
}

int eval_ints(int lhs, int rhs, char sign)
{
    switch (sign)
    {
    case '+':
        return lhs + rhs;

    case '*':
        return lhs * rhs;

    case '^':
        return pow_int(lhs, rhs);

    default:
        return 0;
    }
}

int evaluate_expression(char *exp)
{
    if (count_parentheses(exp) == 0)
    {
        return atoi(exp);
    }
    else if (count_parentheses(exp) == 1)
    {
        uint8_t index = 1;

        int lhs;

        char left[MAX_NUM_LEN] = {};
        uint8_t l_index = 0;

        while (is_numeric(exp[index]))
        {
            left[l_index++] = exp[index++];
        }
        lhs = atoi(left);

        char sign = exp[index++];

        int rhs;
        char right[MAX_NUM_LEN] = {};

        uint8_t r_index = 0;

        while (exp[index] != ')')
        {
            right[r_index++] = exp[index++];
        }
        rhs = atoi(right);

        return eval_ints(lhs, rhs, sign);
    }
    else
    {
        int index = 1;

        int lhs;

        char left[MAX_ARR_LEN] = {};
        uint8_t l_index = 0;

        char sign;

        if (exp[index] == '(')
        {
            uint8_t parentheses_counter = 0;
            do
            {
                if (exp[index] == '(')
                {
                    parentheses_counter++;
                }
                else if (exp[index] == ')')
                {
                    parentheses_counter--;
                }

                left[l_index++] = exp[index++];
            } while (parentheses_counter);
        }
        else
        {
            while (!is_sign(exp[index]))
            {
                left[l_index++] = exp[index++];
            }
        }

        lhs = evaluate_expression(left);
        sign = exp[index];

        int rhs;

        char right[MAX_ARR_LEN] = {};
        uint8_t r_index = 0;

        index++;

        if (exp[index] == '(')
        {
            uint8_t parentheses_counter = 0;
            do
            {
                if (exp[index] == '(')
                {
                    parentheses_counter++;
                }
                else if (exp[index] == ')')
                {
                    parentheses_counter--;
                }

                right[r_index++] = exp[index++];
            } while (parentheses_counter);
        }
        else
        {
            while (exp[index] != '\0')
            {
                right[r_index++] = exp[index++];
            }
        }

        rhs = evaluate_expression(right);

        return eval_ints(lhs, rhs, sign);
    }
}