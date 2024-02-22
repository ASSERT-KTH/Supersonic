#include <stdio.h>
#include <string.h>

#define R_SIZE 99

int main() {
    unsigned int R[R_SIZE / (sizeof(unsigned int) * 8)] = {0}; // Bitset to replace R array

    int i = 0, h = 0, b = 0;
    int c;

    while (read(0, &c, 1) > 0) {
        b += !!(R[c / (sizeof(unsigned int) * 8)] & (1 << (c % (sizeof(unsigned int) * 8))));
        h += !(R[c / (sizeof(unsigned int) * 8)] ^= (1 << (c % (sizeof(unsigned int) * 8))));

        i++;
        if (i > 9) {
            i = h = b = !printf("%d %d\n", h, b - h);
            memset(R, 0, sizeof(R)); // Reset the bitset
        }
    }

    return 0;
}