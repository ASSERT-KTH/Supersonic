#include <stdio.h>

int main() {
    int b, d = 0;
    scanf("%d", &b);
    int c[b];
    for (int i = 0; i < b; i++) {
        int x;
        scanf("%d", &x);
        c[x-1] = 1;
    }
    for (int i = 0; i < b; i++) {
        int x;
        scanf("%d", &x);
        if (c[x-1] == 1) {
            d++;
            c[x-1] = 0;
        }
    }
    printf("%d\n", d);
    return 0;
}