#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  long long min_val = LLONG_MAX; // Initialize to maximum possible value
  long long max_val = LLONG_MIN; // Initialize to minimum possible value
  long long sum = 0;             // Initialize sum to 0

  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    min_val = std::min(min_val, ii); // Update min_val if ii is smaller
    max_val = std::max(max_val, ii); // Update max_val if ii is larger
    sum += ii;                       // Add ii to the sum
  }

  std::cout << min_val << " " << max_val << " " << sum << std::endl;

  return 0;
}