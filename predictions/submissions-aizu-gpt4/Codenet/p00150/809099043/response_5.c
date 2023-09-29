#include <stdio.h>
#include <math.h>

int isprime1(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    int sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, p, q;
    while (scanf("%d", &n) && n > 0) {
        for (q = n; q >= 5; q--) {
            p = q - 2;
            if (isprime1(p) && isprime1(q)) {
                printf("%d %d\n", p, q);
                break;
            }
        }
    }
    return 0;
}