#include <stdio.h>

int main() {
    int c[5004], d[5004], m, t, u, i, f = "%d\n", x;
    scanf("%d%*d", &x);

    for (i = 0; i < x; i++) {
        scanf(f, &c[i]); 
    }

    while(scanf(f, &x) != EOF){
        for (u = i = t = 0; i < x; i++) {
            if (x - c[i]) {
                d[i] = m < u ? m = u : u;
                u = t + 1;
            } else {
                u = d[i];
                d[i] = t;
            }
            t = d[i];
        }
    }
    
    printf(f, m);
    return 0;
}