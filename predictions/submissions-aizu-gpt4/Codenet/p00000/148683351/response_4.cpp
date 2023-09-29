#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            std::cout << i << "x" << j << "=" << i * j << '\n';
        }
    }
    return 0;
}