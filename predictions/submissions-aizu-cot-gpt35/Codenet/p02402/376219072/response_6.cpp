#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<long long> a(n);
  std::copy_n(std::istream_iterator<long long>(std::cin), n, a.begin());

  long long minimum = *std::min_element(a.begin(), a.end());
  long long maximum = *std::max_element(a.begin(), a.end());
  long long sum = std::accumulate(a.begin(), a.end(), 0LL);

  std::cout << minimum << " " << maximum << " " << sum << std::endl;
}