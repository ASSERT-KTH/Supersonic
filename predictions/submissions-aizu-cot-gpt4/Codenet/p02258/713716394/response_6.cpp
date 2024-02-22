#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  int maxProfit = 1 - 1000000000;
  int Ri = 2000000000;
  std::cin >> n;
  std::vector<int> R;
  R.reserve(n);
  
  for (int i = 0; i < n; i++) {
    int temp;
    std::cin >> temp;
    R.push_back(temp);
  }
  
  for (const auto& val : R) {
    if (maxProfit < val - Ri) {
      maxProfit = val - Ri;
    }
    if (val < Ri) {
      Ri = val;
    }
  }
  std::cout << maxProfit << "\n";
  return 0;
}