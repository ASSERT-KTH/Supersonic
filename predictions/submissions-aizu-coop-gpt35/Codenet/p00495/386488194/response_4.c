#include <stdio.h>
#include <stdlib.h>

int main() {
    int *c, *d;
    int n, x, m = 0;
    const char *f = "%d\n";

    scanf("%d%*d", &n);

    // Dynamically allocate memory for c and d arrays
    c = (int *)malloc(n * sizeof(int));
    d = (int *)malloc(n * sizeof(int));

    // Read input values into c array
    for (int i = 0; i < n; i++) {
        scanf(f, &c[i]);
    }

    // Process input values
    while (~scanf(f, &x)) {
        int u = 0;
        for (int i = 0; i < n; i += 2) {
            int t = d[i];
            if (x == c[i]) {
                u = t + 1;
            }
            d[i] = m < u ? m : u;
            m = m < u ? u : m;
        }
    }

    // Free allocated memory
    free(c);
    free(d);

    // Print the result
    printf(f, m);

    return 0;
}