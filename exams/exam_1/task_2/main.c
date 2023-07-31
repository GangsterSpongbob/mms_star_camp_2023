#include <stdio.h>

#include "bit_funcs.h"

int main(void)
{
    __uint64_t mask1 = 12456265;
    __uint32_t mask2 = 34453;
    __uint16_t mask3 = 723;
    __uint8_t mask4 = 49;

    printf("%s%d\n", "Ones count is ", ones_count(mask1, mask2, mask3, mask4));

    __uint64_t pre_flip = 0;
    flip_odd_bits(&pre_flip);
    printf("%s%ld\n", "Flipping odd bits of 0 results in ", pre_flip);

    __uint64_t alt_flip = 0;
    flip_alternative(&alt_flip);
    printf("%s%ld\n", "Alt flipping odd bits of 0 results in ", alt_flip);

    __uint16_t pre_mirror = 0b1111111100000000;
    mirror_bits(&pre_mirror);
    printf("%s%d%s%d\n", "After mirroring ", 0b1111111100000000, " result is ", pre_mirror);
}