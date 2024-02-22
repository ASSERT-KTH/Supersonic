#include <iostream>

int main() {
  int n;
  int maxProfit = 1 - 1000000000;
  int Ri = 2000000000;
  std::cin >> n;
  int R[n];
  for (int i = 0; i < n; i++) {
    std::cin >> R[i];
    if (maxProfit < R[i] - Ri) {
      maxProfit = R[i] - Ri;
    }
    if (R[i] < Ri) {
      Ri = R[i];
    }
  }
  std::cout << maxProfit << std::endl;
  return 0;
}