#include <stdio.h>
#include <string.h>

int i, m, h, t, a;

int main() {
    char s[201], temp;
    while (scanf("%s%d", s, &m), s[0] != '-') {
        a = strlen(s);
        for (i = t = 0; i < m; scanf("%d", &h), t += h, i++)
            ;
        t %= a;
        while (t--) {
            temp = s[0];
            for (i = 0; i < a - 1; i++)
                s[i] = s[i + 1];
            s[a - 1] = temp;
        }
        puts(s);
    }
    return 0;
}