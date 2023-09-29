#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define SIZE 232

int R[SIZE];
int i, h, b;

int main() {
    char c;
    while (read(0, &c, 1) > 0) {
        b += !!R[(unsigned char)c];
        h += !(R[(unsigned char)c] ^= 1 << i % 5);
        if (++i > 9) {
            printf("%d %d\n", h, b - h);
            memset(R, 0, sizeof(R));
            i = h = b = 0;
        }
    }
    return 0;
}