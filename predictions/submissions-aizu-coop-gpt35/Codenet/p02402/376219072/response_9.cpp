#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  // Pre-allocate vector 'a'
  std::vector<long long> a(n);

  // Initialize variables for min, max, and sum
  long long min_value = LLONG_MAX;
  long long max_value = LLONG_MIN;
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];

    // Update min and max values
    min_value = std::min(min_value, a[i]);
    max_value = std::max(max_value, a[i]);

    // Accumulate sum
    sum += a[i];
  }

  // Print min, max, and sum values
  std::cout << min_value << " " << max_value << " " << sum << std::endl;

  return 0;
}