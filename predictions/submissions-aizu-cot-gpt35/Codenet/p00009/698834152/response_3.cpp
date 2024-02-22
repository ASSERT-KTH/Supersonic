#include <iostream>

#define MAX 999999

int main() {
    int n;
    bool not_prime_flag[MAX + 1] = { false };
    int num_prime = 0;

    for (int i = 2; i < MAX + 1; ++i) {
        if (!not_prime_flag[i]) {
            ++num_prime;
            for (int j = i * 2; j < MAX + 1; j += i) {
                not_prime_flag[j] = true;
            }
        }
    }

    while (std::cin >> n) {
        std::cout << num_prime << std::endl;
    }

    return 0;
}