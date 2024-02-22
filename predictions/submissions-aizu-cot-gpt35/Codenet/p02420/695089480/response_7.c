#include <stdio.h>
#include <string.h>

int main() {
    char s[201];
    int m;

    while (scanf("%s%d", s, &m) == 2) {
        if (s[0] == '-') {
            break;
        }

        int len = strlen(s);
        int t = 0;
        for (int i = 0; i < m; i++) {
            int h;
            scanf("%d", &h);
            t += h;
        }

        for (int i = 0; i < len; i++) {
            printf("%c", s[(t + i) % len]);
        }
        printf("\n");
    }

    return 0;
}