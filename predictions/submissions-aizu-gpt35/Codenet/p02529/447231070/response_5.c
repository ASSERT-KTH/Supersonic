#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, d = 0;
    scanf("%d", &b);
    int* c = (int*) calloc(b+1, sizeof(int));
    for (a = 0; a < b; a++) {
        int temp;
        scanf("%d", &temp);
        c[temp] = 1;
    }
    for (a = 0; a < b; a++) {
        int temp;
        scanf("%d", &temp);
        d += c[temp];
    }
    printf("%d\n", d);
    free(c);
    return 0;
}