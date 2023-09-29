#include <cstdio>
#include <iostream>
#include <cstdint>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    uint16_t n, t;
    std::cin >> n;
    
    uint16_t A[10001] = {0};
    uint16_t min = 10001;

    for (uint16_t i = 0; i < n; ++i) {
        std::cin >> t;
        A[t]++;
        if (t < min) min = t;
    }

    A[min]--;
    std::cout << min;

    for (uint16_t i = min; i <= 10000; ++i) {
        for (uint16_t j = 0; j < A[i]; ++j) {
            std::cout << ' ' << i;
        }
    }
    std::cout << '\n';
    return 0;
}