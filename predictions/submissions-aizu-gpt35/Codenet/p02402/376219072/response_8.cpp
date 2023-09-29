#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
int main() {
  int n;
  std::vector<long long> a;
  std::cin >> n;
  a.reserve(n); // reserve memory for n elements
  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    a.push_back(ii);
  }
  auto min_max = std::minmax_element(a.begin(), a.end());
  std::cout << *min_max.first << " "
            << *min_max.second << " "
            << std::accumulate(a.begin(), a.end(), 0LL) << std::endl;
}