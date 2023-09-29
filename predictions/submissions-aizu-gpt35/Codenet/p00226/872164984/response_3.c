#include <stdio.h>
#include <string.h>

int R[99];

int main() {
    int i = 0, h = 0, b = 0, c;
    while (read(0, &c, 1)) {
        ++i;
        if (i > 9) {
            int printed = printf("%d %d\n", h, b - h);
            memset(R, 0, sizeof(R));
            i = h = b = 0;
            if (!printed) return 0;
        }
        b += !!R[c];
        h += !(R[c] ^= 1 << i % 5);
    }
    return 0;
}