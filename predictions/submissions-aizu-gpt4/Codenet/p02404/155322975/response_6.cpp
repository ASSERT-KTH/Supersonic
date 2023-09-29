#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int H, W;
    while (std::cin >> H >> W, H || W) {
        std::vector<std::string> grid(H, std::string(W, '.'));
        std::fill(grid.begin(), grid.begin() + 1, std::string(W, '#'));
        std::fill(grid.rbegin(), grid.rbegin() + 1, std::string(W, '#'));

        for (int i = 1; i < H - 1; ++i) {
            grid[i][0] = grid[i][W - 1] = '#';
        }

        for (const auto& row : grid) {
            std::cout << row << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}