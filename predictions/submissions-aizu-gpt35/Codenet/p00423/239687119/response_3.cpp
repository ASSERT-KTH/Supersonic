#include <iostream>
#include <vector>

int main() {
    int n;
    std::vector<int> veca, vecb;
    while (std::cin >> n && n != 0) {
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            int game_a, game_b;
            std::cin >> game_a >> game_b;
            if (game_a == game_b) {
                a += game_a;
                b += game_b;
            } else if (game_a > game_b) {
                a += game_a + game_b;
            } else {
                b += game_a + game_b;
            }
        }
        veca.push_back(a);
        vecb.push_back(b);
    }
    for (size_t i = 0; i < veca.size(); ++i) {
        std::cout << veca[i] << " " << vecb[i] << '\n';
    }
    return 0;
}