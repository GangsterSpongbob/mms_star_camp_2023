#ifndef BIT_FUNCS_H
#define BIT_FUNCS_H

#include <stdio.h>

unsigned int ones_count(__uint64_t, __uint32_t, __uint16_t, __uint8_t);
void flip_odd_bits(__uint64_t *);
void mirror_bits(__uint16_t *);
void flip_alternative(__uint64_t *);

#endif // BIT_FUNCS_H