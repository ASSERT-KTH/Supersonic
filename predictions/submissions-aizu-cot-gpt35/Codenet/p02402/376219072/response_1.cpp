#include <iostream>
#include <vector>

int main() {
  int n;
  std::vector<long long> a;

  std::cin >> n;
  a.reserve(n); // Reserve memory for n elements

  long long min_val = LLONG_MAX;
  long long max_val = LLONG_MIN;
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    a.push_back(ii);

    // Update min and max values
    if (ii < min_val) {
      min_val = ii;
    }
    if (ii > max_val) {
      max_val = ii;
    }

    // Calculate sum
    sum += ii;
  }

  std::cout << min_val << " " << max_val << " " << sum << std::endl;
}