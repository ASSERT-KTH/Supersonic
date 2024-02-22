#include <algorithm>
#include <iostream>

int main() {
  long long n;
  while (std::cin >> n && n != 0) {
    long long s = 0;
    long long a = 0;
    for (long long i = 0; i < n; i++) {
      long long num;
      std::cin >> num;
      s += num;
    }
    long long* j = new long long[n - 1];
    for (long long i = 0; i < n - 1; i++) {
      std::cin >> j[i];
    }
    // Sort the array j using quicksort
    std::sort(j, j + n - 1);

    for (long long i = n - 1; i >= 0; i--) {
      s += j[i];
      a = std::max(a, (i + 1) * s);
    }

    std::cout << a << std::endl;

    delete[] j;
  }

  return 0;
}