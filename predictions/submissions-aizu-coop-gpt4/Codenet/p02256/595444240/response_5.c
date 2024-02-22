#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    
    // Compute the GCD using the Euclidean algorithm.
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    
    printf("%d\n", a);
    return 0;
}