#include <stdio.h>

int c[5004], d[5004], m, t, u, i;
char f[] = "%d\n";

int main() {
    scanf(f, &c[0]);
    for (i = 1; i <= c[0]; i++) {
        scanf(f, &c[i]);
    }
    while(scanf(f, &t) != EOF){
        m = u = 0;
        for (i = 1; i <= c[0]; i++) {
            t = d[i];
            if (m < u) {
                m = u;
            }
            d[i] = u;
            if (c[i] == t) {
                u = t + 1;
            }
        }
        if (m < u) {
            m = u;
        }
    }
    printf(f, m);
    return 0;
}