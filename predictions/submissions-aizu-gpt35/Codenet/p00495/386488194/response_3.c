#include <stdio.h>
int c[5004], d[5004], m, t, u, i, n;
const char* f = "%d\n";
int main() {
    scanf("%d%*d", &n);
    for (i = 1; i <= n; ++i) {
        scanf(f, &c[i]);
    }
    while (~scanf(f, &t)) {
        m = 0;
        for (i = 1; i <= n; ++i) {
            u = t - c[i] ? u : d[i];
            d[i] = m < u ? m = u : u + 1;
        }
        m = d[n];
        printf(f, m);
    }
    return 0;
}