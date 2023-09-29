#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  long long min_val = 1e18, max_val = -1e18, sum = 0;
  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    min_val = std::min(min_val, ii);
    max_val = std::max(max_val, ii);
    sum += ii;
  }
  std::cout << min_val << " " << max_val << " " << sum << std::endl;
}