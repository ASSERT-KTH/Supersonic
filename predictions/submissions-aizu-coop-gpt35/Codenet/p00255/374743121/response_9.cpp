#include <algorithm>
#include <iostream>

int main() {
  for (long long i, n, *j, s, a;; std::cout << a << std::endl) {
    std::cin >> n;
    if (!n)
      break;
    j = new long long[n];
    for (i = s = 0; i++ < n; s += a)
      std::cin >> a;
    for (i = n; i > 1; std::cin >> j[--i])
      ;
    // Rest of the code
  }
}