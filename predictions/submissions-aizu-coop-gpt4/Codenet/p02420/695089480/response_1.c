#include <stdio.h>

int main() {
    int i, m, h, t, a;
    char s[201], result[201];

    while (scanf("%s%d", s, &m), s[0] != '-') {
        a = strlen(s);
        for (i = t = 0; i < m; i++) {
            scanf("%d", &h);
            t += h;
        }
        for (i = 0; i < a; i++) {
            result[i] = s[(t + i) % a];
        }
        result[i] = '\0';
        printf("%s\n", result);
    }

    return 0;
}