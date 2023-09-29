#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::pair<int, int>> hw;
    int h, w;
    while (std::cin >> h >> w, h || w) {
        hw.emplace_back(h, w);
    }

    for (const auto &[h, w] : hw) {
        std::string row(w, '#');
        for (int i = 0; i < h; ++i) {
            std::cout << row << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}