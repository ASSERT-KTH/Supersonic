#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a;
  a.reserve(n);
  long long minElement = std::numeric_limits<long long>::max();
  long long maxElement = std::numeric_limits<long long>::min();
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    a.push_back(ii);
    minElement = std::min(minElement, ii);
    maxElement = std::max(maxElement, ii);
    sum += ii;
  }

  std::cout << minElement << " " << maxElement << " " << sum << std::endl;
}