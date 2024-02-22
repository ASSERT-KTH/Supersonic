#include <stdio.h>

#define MAX_CHARS 256

int main() {
    int R[MAX_CHARS] = {0};
    int i = -1, h = 0;

    while (1) {
        int c = getchar();
        if (c == EOF) {
            break;
        }

        ++i;
        if (i > 9) {
            printf("%d %d\n", h, i - h);
            i = h = 0;
            for (int j = 0; j < MAX_CHARS; j++) {
                R[j] = 0;
            }
        }

        h += R[c];
        R[c] = 1;
    }

    return 0;
}