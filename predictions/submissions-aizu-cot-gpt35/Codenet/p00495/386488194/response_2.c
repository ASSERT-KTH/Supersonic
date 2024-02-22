#include <stdio.h>
#include <stdlib.h>

int main() {
    int *c, *d, m, t, u, i, f = "%d\n";
    int coin_count;
    
    scanf("%d%*d", &coin_count);
    
    c = (int*)malloc(coin_count * sizeof(int));
    
    for (i = 0; i < coin_count; i++) {
        c[i] = i + 1;
    }
    
    d = (int*)malloc(coin_count * sizeof(int));
    
    for (scanf(f, &u); ~scanf(f, &u);) {
        for (i = 0, t = 0, m = -1; i < coin_count; i++) {
            u = u - c[i] ? u : t + 1;
            t = d[i];
            d[i] = m < u ? m = u : u;
        }
    }
    
    m = !printf(f, m);
    
    free(c);
    free(d);
    
    return 0;
}