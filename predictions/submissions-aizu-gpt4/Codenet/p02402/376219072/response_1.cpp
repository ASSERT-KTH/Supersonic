#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n); // Reserve the size of the array beforehand
  for (auto &e : a)
    std::cin >> e;

  auto [min, max] = std::minmax_element(a.begin(), a.end()); // Call minmax_element instead of min_element and max_element separately
  std::cout << *min << " " << *max << " "
            << std::accumulate(a.begin(), a.end(), 0LL) << std::endl;
}