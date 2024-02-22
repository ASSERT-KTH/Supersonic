#include <algorithm>
#include <iostream>

int main() {
  long long n;
  while (std::cin >> n && n != 0) {
    long long s = 0;
    long long a = 0;
    for (long long i = 0; i < n; ++i) {
      long long num;
      std::cin >> num;
      s += num;
    }

    long long* j = new long long[n];
    for (long long i = 0; i < n; ++i) {
      std::cin >> j[i];
    }

    std::partial_sort(j + 1, j + n, j + n);
    std::reverse(j, j + n);

    for (long long i = 0; i < n; ++i) {
      a = std::max(n * (s + j[i]), a);
    }

    std::cout << a << std::endl;

    delete[] j;
  }

  return 0;
}