#include <cstdio>
#include <cstring>

int main() {
    int n, i;
    char t[1000] = {};
    while (scanf("%d", &n) == 1) {
        memset(t, 0, sizeof(t));
        for (; n--; t[i] = t[*t])
            scanf(" %c %c", &i, &t[i]);
        for (scanf("%d", &n); n--; putchar(!t[i] * i + t[i]))
            scanf(" %c", &i);
        putchar('\n');
    }
    return 0;
}