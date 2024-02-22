#include <iostream>
#include <vector>

int main() {
  int n, k;
  while (std::cin >> n >> k, n != 0) {
    std::vector<long long> ac(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> ac[i];
      if (i > 0) {
        ac[i] += ac[i - 1];
      }
    }
    long long res = -1e18;
    for (int i = k - 1; i < n; ++i) {
      res = std::max(res, ac[i] - (i >= k ? ac[i - k] : 0));
    }
    std::cout << res << '\n';
  }
  return 0;
}