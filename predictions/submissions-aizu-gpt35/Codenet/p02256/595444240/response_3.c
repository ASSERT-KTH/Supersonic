#include <stdio.h>
int main() {
    int a, b, c, i;
    scanf("%d%d", &a, &b);
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    printf("%d\n", a);
    return 0;
}