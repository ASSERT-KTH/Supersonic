#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::vector<int> a;
  std::cin >> n;
  a.reserve(n);
  int minValue = std::numeric_limits<int>::max();
  int maxValue = std::numeric_limits<int>::min();
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int value;
    std::cin >> value;
    a.push_back(value);
    minValue = std::min(minValue, value);
    maxValue = std::max(maxValue, value);
    sum += value;
  }
  std::cout << minValue << " " << maxValue << " " << sum << std::endl;
}