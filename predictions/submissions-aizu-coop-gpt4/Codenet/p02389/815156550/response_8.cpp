#include <cstdio>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);  // fast input

    int product = a * b;  // store the result of multiplication

    printf("%d %d\n", product, a * 2 + b * 2);  // fast output

    return 0;
}