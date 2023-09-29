#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  long long n, a;
  while (std::cin >> n && n) {
    std::vector<long long> j(n);
    long long s = 0;
    for (long long i = 0; i < n; ++i) {
      std::cin >> a;
      s += a;
    }
    for (long long i = 0; i < n - 1; ++i)
      std::cin >> j[i];
    std::sort(j.begin(), j.end());
    a = 0;
    for (; n > 0; --n)
      a = std::max(n * s, a + j[n - 1]);
    std::cout << a << std::endl;
  }
  return 0;
}