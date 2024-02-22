#include <iostream>

const int MAX = 999999;

bool not_prime_flag[MAX + 1];

int main() {
    int n;
    int prime_count = 0;

    for (int i = 2; i < MAX + 1; ++i) {
        if (!not_prime_flag[i]) {
            ++prime_count;
            for (int j = i + i; j < MAX + 1; j += i) {
                not_prime_flag[j] = true;
            }
        }
    }

    while (std::cin >> n) {
        std::cout << prime_count << std::endl;
    }

    return 0;
}