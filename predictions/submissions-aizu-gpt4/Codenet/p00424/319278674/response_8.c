#include <stdio.h>
#include <string.h>

int n, t[999];

int main() {
    while(scanf("%d", &n) == 1 && n) {
        memset(t, 0, sizeof t);
        char a, b;
        while(n--) {
            scanf(" %c %c", &a, &b);
            t[a] = b;
        }
        scanf("%d", &n);
        while(n--) {
            scanf(" %c", &a);
            putchar(t[a] ? t[a] : a);
        }
        putchar('\n');
    }
    return 0;
}