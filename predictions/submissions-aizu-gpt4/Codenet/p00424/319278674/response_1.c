#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 999

char t[MAX];

int main() {
    int n, i;
    while(scanf("%d", &n) != EOF) {
        memset(t, 0, sizeof(t));
        for (i = 0; i < n; ++i) {
            scanf(" %c %c", (char *)&i, t + i);
        }
        for (scanf("%d", &n); n--; putchar(t[i])) {
            scanf(" %c", (char *)&i);
        }
        putchar('\n');
    }
    return 0;
}