#include <iostream>
#include <vector>
#include <limits>

int main() {
  int n;
  std::cin >> n;
  
  std::vector<long long> a;
  a.reserve(n);

  long long sum = 0LL;
  long long min = std::numeric_limits<long long>::max();
  long long max = std::numeric_limits<long long>::min();

  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    a.push_back(ii);
    sum += ii;
    if (ii < min) min = ii;
    if (ii > max) max = ii;
  }

  std::cout << min << " " << max << " " << sum << std::endl;
  return 0;
}