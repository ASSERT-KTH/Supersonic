#include <iostream>

int main() {
  int n;
  int maxProfit = 1 - 1000000000;
  int Ri = 2000000000;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int currentValue;
    std::cin >> currentValue;
    if (maxProfit < currentValue - Ri) {
      maxProfit = currentValue - Ri;
    }
    if (currentValue < Ri) {
      Ri = currentValue;
    }
  }
  std::cout << maxProfit << std::endl;
  return 0;
}