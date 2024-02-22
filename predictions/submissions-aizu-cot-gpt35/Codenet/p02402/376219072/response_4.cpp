#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<long long> a;
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    a.push_back(ii);
    sum += ii;
  }

  auto minmax = std::minmax_element(a.begin(), a.end());

  std::cout << *minmax.first << " " << *minmax.second << " " << sum << std::endl;
}