#include <stdio.h>
#include <strings.h>

int n, t[999];

int main() {
    char i;
    while ((n = scanf("%d", &n)) != EOF) {
        bzero(t, sizeof(t));
        for (; n > 0; --n) {
            scanf(" %c %c", &i, t + i);
        }
        scanf("%d", &n);
        for (; n > 0; --n) {
            scanf(" %c", &i);
            putchar(t[i] ? t[i] : i);
        }
        putchar('\n');
    }
    return 0;
}