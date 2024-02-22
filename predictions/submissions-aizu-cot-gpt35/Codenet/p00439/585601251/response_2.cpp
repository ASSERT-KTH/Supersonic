#include <iostream>
#include <vector>

int main() {
  int n, k;
  while (std::cin >> n >> k, n) {
    std::vector<long long> ac;
    ac.reserve(n + 1);
    ac.resize(n + 1, 0);
    
    for (auto& elem : ac) {
      std::cin >> elem;
      elem += (elem - k >= 0) ? ac[elem - k] : 0;
    }

    long long res = -std::numeric_limits<long long>::max();
    for (int i = k; i <= n; ++i) {
      long long diff = ac[i] - ac[i - k];
      res = std::max(res, diff);
    }

    std::cout << res << std::endl;
  }
  
  return 0;
}