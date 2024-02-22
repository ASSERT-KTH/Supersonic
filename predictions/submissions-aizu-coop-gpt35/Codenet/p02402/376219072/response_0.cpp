#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  // Step 1: Avoid unnecessary memory allocation and reallocation
  std::vector<long long> a;
  a.reserve(n);

  // Step 2: Reduce iterations and optimize input
  long long minValue = LLONG_MAX;
  long long maxValue = LLONG_MIN;
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;

    // Step 3: Find the minimum, maximum, and sum in a single pass
    minValue = std::min(minValue, ii);
    maxValue = std::max(maxValue, ii);
    sum += ii;
  }

  // Step 4: Optimize output
  std::cout << minValue << " " << maxValue << " " << sum << std::endl;

  return 0;
}