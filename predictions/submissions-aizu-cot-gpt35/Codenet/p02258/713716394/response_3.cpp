#include <iostream>
#include <vector>

int main() {
  int n;
  int maxProfit = INT_MIN;
  int Ri = 2000000000;
  
  std::cin >> n;
  std::vector<int> R(n);
  
  for (int i = 0; i < n; i++) {
    std::cin >> R[i];
    int profit = R[i] - Ri;
    if (maxProfit < profit) {
      maxProfit = profit;
    }
    if (R[i] < Ri) {
      Ri = R[i];
    }
  }
  
  std::cout << maxProfit << std::endl;
  return 0;
}