#include <stdio.h>
#include <stdlib.h>

int main() {
    int *c, *d;
    int m, t, u, i, f;
    scanf("%d", &f);

    c = (int*) malloc(f * sizeof(int));
    d = (int*) malloc(f * sizeof(int));

    for (i = 0; i < f; i++) {
        scanf("%d", &c[i]);
    }

    int x;
    while (scanf("%d", &x) != EOF) {
        u = 0;
        for (i = 0; i < f; i++) {
            t = u;
            u = (x != c[i]) ? u : t + 1;
            d[i] = (m < u) ? m : u;
        }
        m = d[f - 1];
    }

    printf("%d\n", m);

    free(c);
    free(d);

    return 0;
}