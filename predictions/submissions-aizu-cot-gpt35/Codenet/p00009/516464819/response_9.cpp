#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

void sieve(int n, std::vector<int>& primes) {
  std::vector<bool> v(n + 1, true);
  for (int i = 3, end = std::sqrt(n); i <= end; i += 2) {
    if (!v[i])
      continue;
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      v[j] = false;
  }
  primes.push_back(2);
  for (int i = 3; i <= n; i += 2)
    if (v[i])
      primes.push_back(i);
}

int main() {
  std::vector<int> primes;
  int x;
  while (std::cin >> x) {
    sieve(x, primes);
    int count = 0;
    for (auto p : primes) {
      if (p == x) {
        count++;
        break;
      } else if (p > x) {
        break;
      } else {
        count++;
      }
    }
    std::cout << count << std::endl;
    primes.clear();
  }
  return 0;
}