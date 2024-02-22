#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  long long min_value = LLONG_MAX;
  long long max_value = LLONG_MIN;
  long long total = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    min_value = std::min(min_value, a[i]);
    max_value = std::max(max_value, a[i]);
    total += a[i];
  }
  std::cout << min_value << " " << max_value << " " << total << std::endl;
}