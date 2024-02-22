#include <iostream>
#include <algorithm>
#include <numeric>

int main() {
  for (long long n; std::cin >> n && n != 0;) {
    long long j[99999];
    std::copy_n(std::istream_iterator<long long>(std::cin), n, j);
    std::partial_sort(j + 1, j + n, j + n);
    long long s = std::accumulate(j + 1, j + n + 1, 0LL);
    long long a = n * s;
    std::cout << a << std::endl;
  }
  return 0;
}