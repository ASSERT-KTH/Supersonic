#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<long long> a;
  a.reserve(n); // Reserve memory for the vector

  long long minVal = LLONG_MAX, maxVal = LLONG_MIN, sum = 0;

  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    a.push_back(ii);

    // Calculate min, max, and sum in a single loop
    minVal = std::min(minVal, ii);
    maxVal = std::max(maxVal, ii);
    sum += ii;
  }

  std::cout << minVal << " " << maxVal << " " << sum << std::endl;

  return 0;
}