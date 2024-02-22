#include <stdio.h>

int R[99] = {0};
int i = 0, h = 0, b = 0;

int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
        b += !!R[c];
        h += !(R[c] ^= 1 << i % 5);
        if (++i > 9) {
            printf("%d %d\n", h, b - h);
            for(int j=0; j<99; j++)
                R[j] = 0;
            i = h = b = 0;
        }
    }
    return 0;
}