#ifndef BITWISE_H
#define BITWISE_H

#include <stdint.h>

uint16_t set_bit(uint16_t, uint8_t);
uint8_t check_bit(uint16_t, uint8_t);
uint16_t clear_bit(uint16_t, uint8_t);
void print_bits(uint16_t);

#endif // BITWISE_H