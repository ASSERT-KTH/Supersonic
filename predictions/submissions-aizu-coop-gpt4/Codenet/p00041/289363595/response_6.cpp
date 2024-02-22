#include <stdio.h>

#define PARENS_SIZE 110001

int main() {
    static char parens[PARENS_SIZE];
    memset(parens, '(', PARENS_SIZE - 1);
    parens[PARENS_SIZE - 1] = 0;

    int a[4];

    while (1) {
        for (int i = 0; i < 4; ++i) {
            scanf("%d", &a[i]);
        }

        if (a[0] == 0) {
            break;
        }

        printf("%s", parens);
        printf("%d+%d+%d+%d\n", a[0], a[1], a[2], a[3]);
    }

    return 0;
}