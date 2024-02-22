#include <iostream>
#include <limits>

int main() {
  int n;
  std::cin >> n;
  
  long long minVal = std::numeric_limits<long long>::max();
  long long maxVal = std::numeric_limits<long long>::min();
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    minVal = std::min(minVal, ii);
    maxVal = std::max(maxVal, ii);
    sum += ii;
  }

  std::cout << minVal << " " << maxVal << " " << sum << std::endl;
}