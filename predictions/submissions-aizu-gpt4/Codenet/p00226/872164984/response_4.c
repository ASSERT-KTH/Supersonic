#include <stdio.h>
#include <string.h>

char R[100];
int i, h, b;

int main() {
    char c;
    while ((c = getchar()) != EOF) {
        if (++i > 9) {
            printf("%d %d\n", h, b - h);
            memset(R, 0, sizeof(R));
            i = h = b = 0;
        }
        b += R[c] != 0;
        h += R[c] == 0;
        R[c] ^= 1 << i % 5;
    }
    return 0;
}