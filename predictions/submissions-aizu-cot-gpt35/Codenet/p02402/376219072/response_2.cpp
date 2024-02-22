#include <iostream>
#include <vector>

int main() {
  size_t n;
  std::cin >> n;
  
  std::vector<long long> a;
  a.reserve(n);

  for (size_t i = 0; i < n; ++i) {
    long long ii;
    std::cin >> ii;
    a.emplace_back(ii);
  }

  long long minElement = a[0];
  long long maxElement = a[0];
  long long sum = 0;

  for (const auto& element : a) {
    minElement = std::min(minElement, element);
    maxElement = std::max(maxElement, element);
    sum += element;
  }

  std::cout << minElement << " " << maxElement << " " << sum << std::endl;

  return 0;
}