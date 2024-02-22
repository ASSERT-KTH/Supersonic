#include <stdio.h>

int main() {
    int c[5004] = {0}, d[5004] = {0}, m = 0, t = 0, u = 0, i = 0, x;
    char f[] = "%d\n";
    for (scanf("%d%*d", c); i < *c; scanf(f, ++i + c))
        ;
    while(scanf(f, &x) != EOF) {
        for (u = i = t = 0; i++ < *c; t = d[i], d[i] = m < u ? m = u : u)
            u = x - c[i] ? u : t + 1;
    }
    printf(f, m);
    return 0;
}