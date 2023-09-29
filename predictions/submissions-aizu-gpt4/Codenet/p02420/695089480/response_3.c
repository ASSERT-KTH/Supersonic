#include <stdio.h>
#include <string.h>

int main() {
    char s[201];
    int m, h, t, a;
    while (scanf("%s%d", s, &m), s[0] != '-') {
        a = strlen(s);
        for (int i = 0, t = 0; i < m; ++i) {
            scanf("%d", &h);
            t = (t + h) % a;
        }
        for (int i = 0; i < a; ++i) {
            putchar(s[(t + i) % a]);
        }
        putchar('\n');
    }
    return 0;
}