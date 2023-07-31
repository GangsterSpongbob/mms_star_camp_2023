#ifndef F_A_M_H
#define F_A_M_H

#include <stdio.h>

void filter_and_map(
    const int[],
    size_t,
    int (*)(int),
    int (*)(int),
    int[],
    size_t *);

#endif // F_A_M_H