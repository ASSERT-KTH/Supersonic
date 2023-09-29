#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> S(n);
    for (auto& s : S) {
        std::cin >> s;
    }

    std::stable_sort(S.begin(), S.end());
    for (const auto& s : S) {
        std::cout << s << ' ';
    }
    std::cout << '\n';
    return 0;
}