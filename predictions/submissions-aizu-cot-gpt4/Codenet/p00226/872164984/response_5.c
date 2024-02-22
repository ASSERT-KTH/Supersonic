#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int c) {
    int R[99] = {0}, i = 0, h = 0, b = 0;
    for (; read(0, &c, 1); ++i) {
        if (i > 9) {
            memset(R, 0, sizeof(R));
            printf("%d %d\n", h, b - h);
            i = h = b = 0;
        }
        int shift = 1 << (i - 5 * (i / 5));
        b += R[c] != 0;
        h += !(R[c] ^= shift);
    }
    return 0;
}