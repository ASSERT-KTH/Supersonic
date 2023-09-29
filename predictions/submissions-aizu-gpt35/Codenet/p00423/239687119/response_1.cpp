#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false); // improve input/output performance
    std::cin.tie(nullptr); // improve input performance
    std::cout.tie(nullptr); // improve output performance

    int n;
    std::vector<int> veca, vecb;
    while (std::cin >> n && n != 0) { // read input and check for termination
        int a = 0, b = 0;
        veca.push_back(0); // initialize with 0
        vecb.push_back(0); // initialize with 0
        for (int i = 0; i < n; ++i) {
            int game_a, game_b;
            std::cin >> game_a >> game_b;
            a += game_a;
            b += game_b;
            if (game_a > game_b) {
                veca.push_back(veca.back() + 3); // add 3 points to veca
                vecb.push_back(vecb.back()); // add 0 points to vecb
            } else if (game_a < game_b) {
                veca.push_back(veca.back()); // add 0 points to veca
                vecb.push_back(vecb.back() + 3); // add 3 points to vecb
            } else {
                veca.push_back(veca.back() + 1); // add 1 point to veca
                vecb.push_back(vecb.back() + 1); // add 1 point to vecb
            }
        }
    }

    // output results
    for (size_t i = 1; i < veca.size(); ++i) {
        std::cout << veca[i] - veca[i-1] << " " << vecb[i] - vecb[i-1] << "\n"; // output difference in points
    }

    return 0;
}