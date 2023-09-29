#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int H, W;

    while (std::cin >> H >> W && (H || W)) {
        std::vector<std::string> matrix(H, std::string(W, '.'));

        for (int i = 0; i < H; ++i) {
            matrix[i][0] = matrix[i][W - 1] = '#';
        }

        std::fill(matrix.begin()->begin(), matrix.begin()->end(), '#');
        std::fill(matrix.rbegin()->begin(), matrix.rbegin()->end(), '#');

        for (auto &row : matrix) {
            std::cout << row << "\n";
        }

        std::cout << "\n";
    }

    return 0;
}