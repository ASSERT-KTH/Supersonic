#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, K, B;
    while (std::cin >> N >> K, N || K) {
        std::vector<int> S(K);
        for (int &i : S)
            std::cin >> i;
        while (N--) {
            std::for_each(S.begin(), S.end(), [](int &i) {
                std::cin >> B;
                i -= B;
            });
        }
        std::cout << (std::all_of(S.begin(), S.end(), [](int i){ return i >= 0; }) ? "Yes" : "No") << '\n';
    }
    return 0;
}