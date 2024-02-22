#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, d = 0;
    int* c = NULL;

    scanf("%d", &b);
    c = (int*)malloc(b * sizeof(int));

    for (a = 0; a < b; a++) {
        scanf("%d", &c[a]);
        d += c[a];
    }

    printf("%d\n", d);

    free(c);

    return 0;
}