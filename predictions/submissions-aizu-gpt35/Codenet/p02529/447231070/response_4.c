#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, d = 0;
    scanf("%d", &b);
    int* c = (int*) calloc(b, sizeof(int));
    for (a = 0; a < b; a++) {
        int input;
        scanf("%d", &input);
        if (!c[input-1]) {
            c[input-1] = 1;
            d++;
        }
    }
    printf("%d\n", d);
    free(c);
    return 0;
}