#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, d = 0;
    scanf("%d", &b);

    int* c = calloc(b+1, sizeof(int));

    for (a = b; a > 0; a--) {
        int input;
        scanf("%d", &input);
        if (c[input] == 0) {
            c[input] = 1;
            d++;
        }
    }

    printf("%d\n", d);
    free(c);
    return 0;
}