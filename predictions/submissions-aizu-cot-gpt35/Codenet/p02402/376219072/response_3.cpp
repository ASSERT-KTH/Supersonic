#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(std::istream_iterator<long long>(std::cin), std::istream_iterator<long long>());

  auto min_max = std::minmax_element(a.begin(), a.end());
  long long sum = std::accumulate(a.begin(), a.end(), 0LL);

  std::cout << *min_max.first << " "
            << *min_max.second << " "
            << sum << std::endl;
}