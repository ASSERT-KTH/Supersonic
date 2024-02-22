#include <iostream>

int main() {
    std::size_t n;
    std::cin >> n;

    int R[n];
    for (std::size_t i = 0; i < n; i++) {
        std::cin >> R[i];
    }

    int maxv = R[1] - R[0];
    for (std::size_t i = 0; i < n; i++) {
        maxv = std::max(maxv, R[i] - R[0]);
    }

    std::cout << maxv << std::endl;

    return 0;
}