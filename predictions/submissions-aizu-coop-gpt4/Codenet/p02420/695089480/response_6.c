#include <stdio.h>
int i, m, h, t, a;
int main() {
    char s[101];
    char ch;
    while ((ch = getchar_unlocked()) != '-') {
        a = 0;
        while (ch != ' ') {
            s[a++] = ch;
            ch = getchar_unlocked();
        }
        scanf("%d", &m);
        getchar_unlocked();  // consume newline
        for (i = t = 0; i < m; scanf("%d", &h), t += h, i++)
            getchar_unlocked();  // consume newline
        t %= a;
        for (i = 0; i < a; i++)
            putchar_unlocked(s[(t + i) % a]);
        putchar_unlocked('\n');
        getchar_unlocked();  // consume newline
    }
    return 0;
}