#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> R(n);
    for (int i = 0; i < n; i++) {
        std::cin >> R[i];
    }

    int maxProfit = -2000000000;
    int minPrice = R[0];
    for (int i = 1; i < n; i++) {
        maxProfit = std::max(maxProfit, R[i] - minPrice);
        minPrice = std::min(minPrice, R[i]);
    }
    
    std::cout << maxProfit << '\n';
    return 0;
}