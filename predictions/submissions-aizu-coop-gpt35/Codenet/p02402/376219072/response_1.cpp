#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  // Step 1: Preallocate the vector
  std::vector<long long> a(n);

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  // Step 2: Optimize calculation of min, max, and sum
  long long min_val = a[0];
  long long max_val = a[0];
  long long sum_val = a[0];

  for (int i = 1; i < n; i++) {
    if (a[i] < min_val) {
      min_val = a[i];
    }
    if (a[i] > max_val) {
      max_val = a[i];
    }
    sum_val += a[i];
  }

  std::cout << min_val << " " << max_val << " " << sum_val << std::endl;

  return 0;
}