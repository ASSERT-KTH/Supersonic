#include <iostream>
#include <vector>

int main() {
    int N, K;
    while (std::cin >> N >> K, N || K) {
        std::vector<int> S(K);
        for (auto it = S.rbegin(); it != S.rend(); ++it)
            std::cin >> *it;

        bool a = true;
        for (int i = 0; i < N; ++i)
            for (auto it = S.rbegin(); it != S.rend(); ++it) {
                int B; std::cin >> B;
                if ((*it -= B) < 0)
                    a = false;
            }
        std::cout << (a ? "Yes" : "No") << std::endl;
    }
}