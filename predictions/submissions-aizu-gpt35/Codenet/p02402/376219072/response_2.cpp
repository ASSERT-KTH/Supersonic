#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  auto minmax = std::minmax_element(a.begin(), a.end());
  std::cout << *minmax.first << " " << *minmax.second << " "
            << std::accumulate(a.begin(), a.end(), 0LL) << "\n";
  return 0;
}