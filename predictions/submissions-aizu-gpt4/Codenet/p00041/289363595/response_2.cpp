#include <stdio.h>

int main() {
    int a[4];
    while (scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]), a[0]) {
        fputs("(", stdout);
        for (int i = 1; i < 110000; ++i)
            putchar_unlocked('(');
        printf("%d+%d+%d+%d)\n", a[0], a[1], a[2], a[3]);
    }
}