#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> R(n);
    for (int& r : R) {
        std::cin >> r;
    }
    int minElement = *std::min_element(R.begin(), R.end());
    int maxProfit = *std::max_element(R.begin(), R.end()) - minElement;
    std::cout << maxProfit << std::endl;
    return 0;
}