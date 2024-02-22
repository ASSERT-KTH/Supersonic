#include <iostream>
#include <vector>
#include <climits>

int main() {
  int n, k;
  while (std::cin >> n >> k, n) {
    std::vector<long long> ac(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      std::cin >> ac[i];
      ac[i] += ac[i - 1];
    }
    long long res = -LLONG_MAX;
    for (int i = k; i <= n; ++i) {
      res = std::max(res, ac[i] - ac[i - k]);
    }
    std::cout << res << std::endl;
  }
  return 0;
}