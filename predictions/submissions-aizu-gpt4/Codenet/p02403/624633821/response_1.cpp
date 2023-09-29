#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::pair<int, int>> dimensions;
    while (true) {
        int h, w;
        std::cin >> h >> w;
        if (h == 0 && w == 0) break;
        dimensions.emplace_back(h, w);
    }

    for (const auto& dim : dimensions) {
        std::string row(dim.second, '#');
        for (int i = 0; i < dim.first; ++i) {
            std::cout << row << '\n';
        }
        std::cout << '\n';
    }

    return 0;
}