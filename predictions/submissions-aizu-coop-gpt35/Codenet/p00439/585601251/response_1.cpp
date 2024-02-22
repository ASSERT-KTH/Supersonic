#include <iostream>
#include <vector>
#include <cstdint>

int main() {
  int n, k;
  while (std::cin >> n >> k, n) {
    std::vector<int64_t> ac(n + 1);
    for (int i = 1; i <= n; ++i) {
      std::cin >> ac[i];
      ac[i] += ac[i - 1];
    }
    int64_t res = INT64_MIN;
    for (int i = k; i < n; ++i) {
      int64_t sum = ac[i] - ac[i - k];
      if (sum > res) {
        res = sum;
      }
    }
    std::cout << res << std::endl;
  }
  return 0;
}