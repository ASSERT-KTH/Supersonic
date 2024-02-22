#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a;
  a.reserve(n);  // reserve memory in advance
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    a.push_back(ii);
    sum += ii;  // accumulate sum while reading inputs
  }
  auto minmax = std::minmax_element(a.begin(), a.end());  // find min and max with a single traversal
  std::cout << *minmax.first << " " << *minmax.second << " " << sum << std::endl;
}