#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  long long min_num = 2e9, max_num = -2e9, sum = 0;
  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    min_num = std::min(min_num, ii);
    max_num = std::max(max_num, ii);
    sum += ii;
  }
  std::cout << min_num << " " << max_num << " " << sum << std::endl;
}