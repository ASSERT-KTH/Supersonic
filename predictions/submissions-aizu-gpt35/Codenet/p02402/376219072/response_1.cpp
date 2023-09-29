#include <iostream>
#include <vector>
int main() {
  int n;
  std::vector<long long> a;
  long long max = -1e18, min = 1e18, sum = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    max = std::max(max, ii);
    min = std::min(min, ii);
    sum += ii;
  }
  std::cout << min << " " << max << " " << sum << std::endl;
}