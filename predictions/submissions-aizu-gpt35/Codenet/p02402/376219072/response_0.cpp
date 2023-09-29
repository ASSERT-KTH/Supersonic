#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  auto min_max = std::minmax_element(a.begin(), a.end());
  std::cout << *min_max.first << " "
            << *min_max.second << " "
            << std::accumulate(a.begin(), a.end(), 0LL) << std::endl;
}