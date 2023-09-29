#include <stdio.h>
#include <string.h>

int main() {
    int n, i;
    char t[1001] = {0};
    while(scanf("%d", &n) == 1) {
        memset(t, 0, sizeof(t));
        for(i = 0; i < n; ++i) {
            char c1, c2;
            scanf(" %c %c", &c1, &c2);
            t[c1] = c2;
        }
        scanf("%d", &n);
        char c;
        getchar();
        while(n--) {
            i = 0;
            while(scanf("%c", &c) == 1 && c != '\n') {
                putchar(t[c] ? t[c] : c);
            }
            putchar('\n');
        }
    }
    return 0;
}