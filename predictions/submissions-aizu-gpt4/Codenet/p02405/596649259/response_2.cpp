#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W;
    while (std::cin >> H >> W && H != 0 && W != 0) {
        std::string line1 = std::string(W / 2, ".#") + std::string(W % 2, '.');
        std::string line2 = std::string(W / 2, "#.") + std::string(W % 2, '#');
        for (int i = 1; i <= H; ++i) {
            std::cout << ((i % 2) ? line1 : line2) << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}