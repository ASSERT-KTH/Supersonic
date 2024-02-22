#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime[1000000];  // assuming n will not exceed 1000000

void calculate_prime(int n) {
    for(int i = 0; i <= n; i++)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    int n, p, q, i;
    scanf("%d", &n);
    while (n) {
        calculate_prime(n);
        for (i = n; n >= 5; i--) {
            if (is_prime[i] && is_prime[i - 2]) {
                p = i - 2;
                q = i;
                break;
            }
        }
        printf("%d %d\n", p, q);
        scanf("%d", &n);
    }
    return 0;
}