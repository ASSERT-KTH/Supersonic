#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int H, W;

    while (std::cin >> H >> W && H && W) {
        std::vector<std::string> matrix(H, std::string(W, '.'));

        std::fill(matrix.front().begin(), matrix.front().end(), '#');
        std::fill(matrix.back().begin(), matrix.back().end(), '#');

        for (int i = 1; i < H - 1; ++i) {
            matrix[i].front() = '#';
            matrix[i].back() = '#';
        }

        for (const auto &row : matrix) {
            std::cout << row << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}