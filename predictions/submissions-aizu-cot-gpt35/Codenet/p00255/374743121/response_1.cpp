#include <iostream>
#include <algorithm>

int main() {
  long long n;
  while (std::cin >> n && n != 0) {
    long long s = 0;
    for (long long i = 0; i < n; ++i) {
      long long a;
      std::cin >> a;
      s += a;
    }
    long long j[99999];
    for (long long i = n; i >= 1; --i) {
      std::cin >> j[i];
    }
    std::sort(j + 1, j + n + 1);
    long long a = 0;
    for (long long i = n; i >= 1; --i) {
      s += j[i];
      a = std::max(a, i * s);
    }
    std::cout << a << std::endl;
  }
  return 0;
}