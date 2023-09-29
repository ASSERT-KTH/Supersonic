#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int H, W;
    std::vector<std::vector<char>> grid(300, std::vector<char>(300));
    
    while (std::cin >> H >> W && H && W) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                grid[i][j] = ".#"[(i + j) & 1];
            }
            grid[i][W] = '\n';
        }
        grid[H][0] = '\n';
        std::cout.write(reinterpret_cast<char*>(grid.data()), H * W + H + 1);
    }
    return 0;
}