#include <iostream>
#include <bitset>
#include <cmath>

const int MAX = 999999;

int main() {
    int n;
    std::bitset<MAX + 1> not_prime_flag;
    int num_primes = 0;

    for (int i = 3; i <= std::sqrt(MAX); i += 2) {
        if (!not_prime_flag[i]) {
            for (int j = i * i; j <= MAX; j += 2 * i) {
                not_prime_flag[j] = true;
            }
        }
    }

    for (int i = 3; i <= MAX; i += 2) {
        if (!not_prime_flag[i]) {
            num_primes++;
        }
    }

    while (std::cin >> n) {
        if (n == 0) break;
        std::cout << num_primes << std::endl;
    }

    return 0;
}