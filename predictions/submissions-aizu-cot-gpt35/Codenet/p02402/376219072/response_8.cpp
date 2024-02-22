#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> a;
  a.reserve(n);

  for (int i = 0; i < n; i++) {
    int ii;
    std::cin >> ii;
    a.push_back(ii);
  }

  int minElement = a[0];
  int maxElement = a[0];
  long long sum = 0;

  for (const auto& element : a) {
    minElement = std::min(minElement, element);
    maxElement = std::max(maxElement, element);
    sum += element;
  }

  std::cout << minElement << " " << maxElement << " " << sum << '\n';

  return 0;
}