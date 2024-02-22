#include <iostream>
#include <vector>
#include <climits>

int main() {
  int n, k;
  while (std::cin >> n >> k, n) {
    std::vector<int> ac(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      std::cin >> ac[i];
      ac[i] += ac[i - 1];
    }
    int res = INT_MIN;
    for (int i = k; i <= n; ++i) {
      int currentSum = ac[i] - ac[i - k - 1];
      res = std::max(res, currentSum);
    }
    std::cout << res << std::endl;
  }
  return 0;
}