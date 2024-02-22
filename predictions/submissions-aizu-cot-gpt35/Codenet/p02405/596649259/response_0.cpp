#include <iostream>

int main() {
    int H, W;
    std::cin >> H >> W;
    while (H != 0 && W != 0) {
        int mod = (H + W) % 2;
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                std::cout << (".#"[mod]);
                mod = 1 - mod;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cin >> H >> W;
    }
    return 0;
}