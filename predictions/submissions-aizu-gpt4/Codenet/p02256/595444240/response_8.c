#include <stdio.h>
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    printf("%d\n", a);
}