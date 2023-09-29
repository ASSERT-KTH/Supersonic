#include <iostream>
#include <vector>

int main() {
    int n, game_a, game_b;
    int a = 0, b = 0;
    std::vector<int> veca, vecb;
    veca.reserve(100);
    vecb.reserve(100);

    while (std::cin >> n && n != 0) {
        for (int i = 0; i < n; ++i) {
            std::cin >> game_a >> game_b;
            game_a > game_b ? a += game_a + game_b : b += game_a + game_b;
        }
        veca.push_back(a);
        vecb.push_back(b);
        a = b = 0;
    }

    for (size_t i = 0, e = veca.size(); i < e; ++i) {
        std::cout << veca[i] << ' ' << vecb[i] << '\n';
    }

    return 0;
}