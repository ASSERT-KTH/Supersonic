#include <stdio.h>
#include <string.h>

#define MAX_N 999

int main() {
    int n, i;
    char t[MAX_N];
    while (scanf("%d", &n) == 1) {
        memset(t, 0, sizeof(t));
        for (i = 0; i < n; i++) {
            char c1, c2;
            scanf(" %c %c", &c1, &c2);
            t[c1 - 'a'] = c2;
        }
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            char c;
            scanf(" %c", &c);
            putchar(t[c - 'a'] ? t[c - 'a'] : c);
        }
        putchar('\n');
    }
    return 0;
}