#include <iostream>
#include <cstdio>
const int MAX = 999999;

int main() {
    bool not_prime_flag[MAX + 1] = {false};
    int prime_count = 0;

    for (int i = 3; i <= MAX; i += 2) {
        if (!not_prime_flag[i]) {
            for (int j = i; j <= MAX; j += 2 * i) {
                not_prime_flag[j] = true;
            }
            prime_count++;
        }
    }

    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", prime_count + 1);
    }

    return 0;
}