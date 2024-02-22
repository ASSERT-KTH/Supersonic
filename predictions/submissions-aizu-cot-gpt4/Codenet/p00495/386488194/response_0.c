#include <stdio.h>

int main() {
    int c[5004], d[5004], m = 0, t, u, i = 0, x;
    for (scanf("%d%*d", c); i < *c; scanf("%d", ++i + c))
        ;
    while(scanf("%d", &x) == 1) {
        for (u = i = t = 0; i++ < *c; t = d[i], d[i] = m < u ? m = u : u)
            u = x - c[i] ? u : t + 1;
    }
    printf("%d\n", m);
    m = 0;
    return 0;
}