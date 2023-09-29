#include <stdio.h>

int c[5004], d[5004], m, t, u, i;
const char* f = "%d\n";
int main() {
    scanf("%d%*d", c);
    for (i = 1; i <= *c; i++)
        scanf(f, &c[i]);

    while (~scanf(f, &t)) {
        u = m = 0;
        for (i = 1; i <= *c; i++) {
            t = d[i];
            if (c[i] == t) {
                u++;
                if (u > m)
                    m = u;
            } else {
                u = 0;
            }
            d[i] = u;
        }
    }
    printf(f, m);
    return 0;
}