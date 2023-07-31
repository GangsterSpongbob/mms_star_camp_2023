#ifndef IO_FUNCS_H
#define IO_FUNCS_H

#include <stdint.h>

#define MAX_NUM_LEN 16
#define MAX_ARR_LEN 128

uint8_t is_sign(char c);
int eval_ints(int lhs, int rhs, char sign);
uint8_t count_parentheses(char *str);
int evaluate_expression(char *exp);

#endif // IO_FUNCS_H