#include <iostream>
#include <vector>
#include <limits>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  long long minNum = std::numeric_limits<long long>::max();
  long long maxNum = std::numeric_limits<long long>::min();
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    minNum = std::min(minNum, a[i]);
    maxNum = std::max(maxNum, a[i]);
    sum += a[i];
  }

  std::cout << minNum << " " << maxNum << " " << sum << std::endl;

  return 0;
}