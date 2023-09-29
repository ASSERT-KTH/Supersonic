#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int H, W;
    while (std::cin >> H >> W && H != 0 && W != 0) {
        std::vector<std::string> matrix(H, std::string(W, '.'));
        for (int i = 0; i < H; ++i) {
            for (int j = i % 2; j < W; j += 2) {
                matrix[i][j] = '#';
            }
        }
        for (const auto &row : matrix) {
            std::cout << row << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}