#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int H, W;
    while (std::cin >> H >> W, H || W) {
        std::vector<std::string> field(H, std::string(W, '.'));

        std::fill(field.begin()->begin(), field.begin()->end(), '#');
        std::fill(field.rbegin()->begin(), field.rbegin()->end(), '#');

        for (auto &row : field) {
            row.front() = '#';
            row.back() = '#';
        }

        for (const auto &row : field) {
            std::cout << row << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}