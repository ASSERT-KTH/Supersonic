#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate_frequency() {
    char R[99] = {0};
    int i = 0, h = 0, b = 0;
    char c;
    while (read(0, &c, 1)) {
        int temp = !!R[c];
        b += temp;
        R[c] ^= 1 << i % 5;
        h += !temp;
        if (++i > 9) {
            printf("%d %d\n", h, b - h);
            memset(R, 0, sizeof(R));
            i = h = b = 0;
        }
    }
}

int main() {
    calculate_frequency();
    return 0;
}