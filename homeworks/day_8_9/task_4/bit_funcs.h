#ifndef BIT_FUNCS_H
#define BIT_FUNCS_H

#include <stdint.h>
#include <stdlib.h>

int clear_bits(uint32_t *, size_t, size_t);
int set_bits(uint32_t *, size_t, size_t);
int check_bits(uint32_t *, size_t, size_t);

#endif // BIT_FUNCS_H