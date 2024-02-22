#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  const int maxProfit = INT_MIN;
  int Ri = 2000000000;
  std::cin >> n;
  std::vector<int> R;
  R.reserve(n);
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    R.push_back(num);
  }
  for (const auto& num : R) {
    maxProfit = std::max(maxProfit, num - Ri);
    Ri = std::min(Ri, num);
  }
  std::cout << maxProfit << std::endl;
  return 0;
}