#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int main() {
  int n;
  int maxProfit = std::numeric_limits<int>::min();
  int Ri = 2000000000;
  std::cin >> n;
  std::vector<int> R;
  R.reserve(n);
  for (auto& r : R) {
    std::cin >> r;
  }
  for (const auto& r : R) {
    maxProfit = std::max(maxProfit, r - Ri);
    Ri = std::min(Ri, r);
  }
  std::cout << maxProfit << std::endl;
  return 0;
}