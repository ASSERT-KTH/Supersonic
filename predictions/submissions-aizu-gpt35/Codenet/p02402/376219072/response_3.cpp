#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }
  auto [min_it, max_it] = std::minmax_element(a.begin(), a.end());
  std::cout << *min_it << " " << *max_it << " " << sum << std::endl;
}