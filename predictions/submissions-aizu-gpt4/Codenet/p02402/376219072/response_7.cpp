#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  for (auto& val : a) {
    std::cin >> val;
  }
  auto [min_el, max_el] = std::minmax_element(a.begin(), a.end());
  std::cout << *min_el << " " << *max_el << " "
            << std::accumulate(a.begin(), a.end(), 0LL) << std::endl;
}