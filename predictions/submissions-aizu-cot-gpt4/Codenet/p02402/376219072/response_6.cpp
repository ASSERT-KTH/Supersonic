#include <iostream>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a;
  a.reserve(n);
  long long min_val = LLONG_MAX;
  long long max_val = LLONG_MIN;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    a.push_back(ii);
    min_val = std::min(min_val, ii);
    max_val = std::max(max_val, ii);
    sum += ii;
  }
  std::cout << min_val << " " << max_val << " " << sum << std::endl;
}