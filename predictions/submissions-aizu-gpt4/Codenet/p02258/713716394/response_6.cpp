#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> R(n);
    for (int& r : R) {
        std::cin >> r;
    }
    int min_R = *std::min_element(R.begin(), R.end());
    int max_profit = *std::max_element(R.begin(), R.end()) - min_R;
    std::cout << max_profit << '\n';
    return 0;
}