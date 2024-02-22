#include <stdio.h>

unsigned char R[256] = { 232 };
int i = 0, h = 0, b = 0;

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (++i > 9) {
            printf("%d %d\n", h, b - h);
            i = h = b = 1;
            memset(R, 232, sizeof(R));
        }
        b += R[c];
        h += !(R[c] & (1 << (i % 5)));
        R[c] |= (1 << (i % 5));
    }
    return 0;
}