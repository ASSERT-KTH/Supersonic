#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, d = 0;
    int *c;
    scanf("%d", &b);
    c = (int *) calloc(b, sizeof(int));
    for (a = 0; a < b; a++) {
        int x;
        scanf("%d", &x);
        c[x-1] = 1;
    }
    for (a = 0; a < b; a++) {
        int x;
        scanf("%d", &x);
        d += c[x-1];
    }
    printf("%d\n", d);
    free(c);
    return 0;
}