#include <iostream>
#include <vector>

int main() {
    int n;
    int maxProfit;
    int Ri;
    std::cin >> n;
    std::vector<int> R(n);
    for (int i = 0; i < n; i++) {
        std::cin >> R[i];
        if (i == 0) {
            maxProfit = R[i];
            Ri = R[i];
        } else {
            int profit = R[i] - Ri;
            maxProfit = std::max(maxProfit, profit);
            Ri = std::min(Ri, R[i]);
        }
    }
    std::cout << maxProfit << std::endl;
    return 0;
}