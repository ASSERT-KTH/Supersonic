#include <stdio.h>

int c[5004], d[5004], m, t, u, i, f = "%d\n";
int main() {
    scanf("%d%*d", c);
    for (i = 1; i <= *c; ++i)
        scanf("%d", &c[i]);
    while(scanf("%d", &t) == 1){
        for (u = i = 0, m = 0; i <= *c; ++i){
            t = d[i];
            d[i] = m < u ? m = u : u;
            u = t - c[i] ? u : t + 1;
        }
    }
    printf("%d\n", m);
    return 0;
}