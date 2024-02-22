#include <iostream>
#include <vector>
#include <cstdio>

int main() {
    const int N = 999999;
    std::vector<bool> not_prime_flag(N + 1, false);
    int count = 0;
    
    for (int i = 2; i <= N; ++i) {
        if (!not_prime_flag[i]) {
            ++count;
            for (int j = i * i; j <= N; j += i) {
                not_prime_flag[j] = true;
            }
        }
    }
    
    int n;
    while (std::scanf("%d", &n) == 1) {
        std::printf("%d\n", count);
    }
    
    return 0;
}