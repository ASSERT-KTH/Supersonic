#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  std::vector<long long> a;
  std::cin >> n;
  a.reserve(n); // reserve memory for the vector
  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    a.push_back(ii);
  }
  auto minmax = std::minmax_element(a.begin(), a.end()); // use minmax_element instead of min_element and max_element
  std::cout << *minmax.first << " "
            << *minmax.second << " "
            << std::accumulate(a.begin(), a.end(), 0LL) << std::endl;
}