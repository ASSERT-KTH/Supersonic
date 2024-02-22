#include <climits>
#include <vector>

int main() {
  int n, k;
  while (std::cin >> n >> k, n) {
    std::vector<long long> ac;
    ac.reserve(n + 1);
    for (int i = 1; i <= n; ++i) {
      long long num;
      std::cin >> num;
      ac.push_back(ac.back() + num);
    }
    long long res = -LLONG_MAX;
    for (int i = k; i <= n; ++i) {
      res = std::max(res, ac[i] - ac[i - k]);
    }
    std::cout << res << std::endl;
  }
  return 0;
}