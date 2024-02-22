#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

char R[99];
int i, h, b;

int main() {
    char buffer[BUF_SIZE];
    int c, counter = 0;

    while ((c = fread(buffer, 1, BUF_SIZE, stdin)) > 0) {
        for (int j = 0; j < c; j++) {
            char byte = buffer[j];
            b += R[byte];
            h += R[byte] = 1 << counter;
            if (++counter > 9) {
                printf("%d %d\n", h, b - h);
                memset(R, 0, sizeof(R));
                counter = i = h = b = 0;
            }
        }
    }

    return 0;
}