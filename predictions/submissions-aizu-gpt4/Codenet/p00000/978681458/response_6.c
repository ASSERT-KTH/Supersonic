#include <stdio.h>

int main(void) {
    int i, j, product[10][10];

    for (i = 1; i < 10; i++) {
        for (j = 1; j < 10; j++) {
            product[i][j] = i * j;
        }
    }

    for (i = 1; i < 10; i++) {
        for (j = 1; j < 10; j++) {
            printf("%dx%d=%d\n", i, j, product[i][j]);
        }
    }

    return (0);
}