#include <stdio.h>
#include <string.h>

int main() {
    char s[201];
    int m, h, t, a, i;

    while (scanf("%s%d", s, &m), s[0] != '-') {
        a = strlen(s);
        for (i = t = 0; i < m; i++) {
            scanf("%d", &h);
            t = (t + h) % a;
        }
        for (i = 0; i < a; i++) {
            printf("%c", s[(t + i) % a]);
        }
        puts("");
    }

    return 0;
}