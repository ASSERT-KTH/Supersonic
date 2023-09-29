#include <stdio.h>
#include <string.h>
#include <unistd.h>

char R[99] = {0};
int i = 0, h = 0, b = 0;

int main() {
    char c;
    while(read(STDIN_FILENO, &c, 1)) {
        b += !!R[(int)c];
        h += !(R[(int)c] ^= 1 << i % 5);
        if (++i > 9) {
            printf("%d %d\n", h, b - h);
            memset(R, 0, sizeof(R));
            i = h = b = 0;
        }
    }
    return 0;
}