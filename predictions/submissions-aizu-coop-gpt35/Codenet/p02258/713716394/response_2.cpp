#include <iostream>

int main() {
  int n;
  constexpr int MAX_PROFIT = -1000000000;
  constexpr int RI = 2000000000;
  std::cin >> n;
  int R[n];
  for (int i = 0; i < n; i++) {
    std::cin >> R[i];
  }
  int maxProfit = R[0] - RI;
  for (int i = 1; i < n; i++) {
    if (maxProfit < R[i] - RI) {
      maxProfit = R[i] - RI;
    }
    if (R[i] < RI) {
      RI = R[i];
    }
  }
  std::cout << maxProfit << std::endl;
  return 0;
}