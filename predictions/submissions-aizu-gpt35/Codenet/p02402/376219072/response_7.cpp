#include <iostream>
#include <vector>
int main() {
  int n, min, max;
  long long sum = 0;
  std::cin >> n >> min;
  max = min;
  sum = min;
  for (int i = 1; i < n; i++) {
    long long ii;
    std::cin >> ii;
    sum += ii;
    if (ii < min) {
      min = ii;
    } else if (ii > max) {
      max = ii;
    }
  }
  std::cout << min << " " << max << " " << sum << std::endl;
}