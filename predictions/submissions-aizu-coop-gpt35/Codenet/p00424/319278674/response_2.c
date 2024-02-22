#include <stdio.h>
#include <string.h>

int main() {
    int n, t[999];
    int i, count, input;

    while (scanf("%d", &input) && input) {
        memset(t, 0, sizeof(t));

        for (count = input; count > 0; count--, t[i] = *t) {
            scanf(" %c %c", &i, t);
        }

        scanf("%d", &input);

        for (count = input; count > 0; count--) {
            scanf(" %c", &i);
            putchar(!t[i] * i + t[i]);
        }

        puts("");
    }

    return 0;
}