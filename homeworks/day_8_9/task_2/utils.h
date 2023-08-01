#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

void *find_max(void *, size_t, size_t, int (*)(const void *, const void *));
int cmp_int(const void *, const void *);

#endif // UTILS_H