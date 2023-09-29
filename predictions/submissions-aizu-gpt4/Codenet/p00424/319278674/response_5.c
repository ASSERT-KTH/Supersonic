#include <stdio.h>
#include <string.h>

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        char t[1000] = {0};
        for(int i = 0; i < n; ++i) {
            char c, v;
            scanf(" %c %c", &c, &v);
            t[c] = v;
        }
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            char c;
            scanf(" %c", &c);
            putchar(t[c] ? t[c] : c);
        }
        putchar('\n');
    }
    return 0;
}