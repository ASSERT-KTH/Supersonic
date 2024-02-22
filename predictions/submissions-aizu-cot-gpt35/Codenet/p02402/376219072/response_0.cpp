#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<long long> a;
  a.reserve(n); // Pre-allocate memory for 'n' elements

  for (auto i = 0; i < n; i++) {
    long long num;
    std::cin >> num;
    a.push_back(num);
  }

  auto min = *std::min_element(a.begin(), a.end());
  auto max = *std::max_element(a.begin(), a.end());
  auto sum = std::accumulate(a.begin(), a.end(), 0LL);

  std::cout << min << " " << max << " " << sum << std::endl;
}