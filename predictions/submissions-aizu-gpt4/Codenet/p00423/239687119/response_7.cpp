#include <iostream>
#include <vector>

int main() {
    int n, game_a, game_b;
    std::vector<int> veca, vecb;
    
    while (std::cin >> n && n != 0) {
        int a = 0, b = 0;

        for (int i = 0; i < n; ++i) {
            std::cin >> game_a >> game_b;

            if (game_a >= game_b) 
                a += game_a + game_b;
            else 
                b += game_a + game_b;
        }
        veca.push_back(a);
        vecb.push_back(b);
    }

    for (size_t i = 0, end = veca.size(); i < end; ++i) {
        std::cout << veca[i] << " " << vecb[i] << '\n';
    }

    return 0;
}