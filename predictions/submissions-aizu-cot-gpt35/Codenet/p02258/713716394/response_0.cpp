#include <iostream>
#include <vector>

int main() {
  int n;
  int maxProfit = -INFINITY;
  std::cin >> n;
  std::vector<int> R(n);
  for (auto& num : R) {
    std::cin >> num;
  }
  int Ri = R[0];
  for (const auto& num : R) {
    if (num - Ri > maxProfit) {
      maxProfit = num - Ri;
    }
    if (num < Ri) {
      Ri = num;
    }
  }
  std::cout << maxProfit << std::endl;
  return 0;
}