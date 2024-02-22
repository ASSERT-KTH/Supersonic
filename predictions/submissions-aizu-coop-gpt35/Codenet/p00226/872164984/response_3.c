#include <stdio.h>
#include <string.h>

#define MAX_COLORS 32

int main() {
    unsigned int R = 0;
    int i = -1, h = 0, b = 0;
    char c;

    while (read(0, &c, 1)) {
        ++i;
        if (i > 9) {
            memset(&R, 0, sizeof(R));
            i = h = b = !printf("%d %d\n", h, b - h);
        }

        int colorIndex = c - 'a';
        unsigned int colorMask = 1 << colorIndex;
        b += !!(R & colorMask);
        h += !(R & colorMask);
        R ^= colorMask;
    }

    return 0;
}