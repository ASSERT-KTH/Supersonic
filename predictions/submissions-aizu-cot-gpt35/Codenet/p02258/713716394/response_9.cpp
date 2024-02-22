#include <iostream>
#include <vector>
#include <climits>

int main() {
  int n;
  int maxProfit = INT_MIN; // Initialize to minimum possible value
  int Ri = INT_MAX; // Initialize to maximum possible value

  std::cin >> n;
  std::vector<int> R(n);

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