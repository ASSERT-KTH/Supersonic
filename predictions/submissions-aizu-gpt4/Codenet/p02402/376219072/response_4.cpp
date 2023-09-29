#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<long long> a(n);
  for (long long& ii : a)
    std::cin >> ii;

  auto [min_it, max_it] = std::minmax_element(a.begin(), a.end());

  std::cout << *min_it << " "
            << *max_it << " "
            << std::accumulate(a.begin(), a.end(), 0LL) << '\n';
}