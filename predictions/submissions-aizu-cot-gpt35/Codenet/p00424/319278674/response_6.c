#include <stdio.h>
#include <string.h>

int main() {
    int n;
    int t[999];

    while (scanf("%d", &n) == 1) {
        memset(t, 0, 999 * sizeof(int));

        for (int i = 0; i < n; i++) {
            scanf(" %d %d", &i, &t[i]);
        }

        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            putchar(!t[i] * i + t[i]);
        }
    }

    return 0;
}