#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char t[1000];
    while (scanf("%d", &n) == 1) {
        memset(t, 0, sizeof(t));
        for (int i = 0; i < n; i++) {
            char c1, c2;
            scanf(" %c %c", &c1, &c2);
            t[c1] = c2;
        }
        scanf("%d", &n);
        getchar(); // consume the newline character after the integer
        for (int i = 0; i < n; i++) {
            char c = getchar();
            putchar(t[c] == 0 ? c : t[c]);
        }
        putchar('\n');
    }
    return 0;
}