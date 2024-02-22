#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  
  std::vector<long long> a;
  a.reserve(n); // Allocate memory upfront
  
  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    a.push_back(ii);
  }
  
  // Find min, max, and sum of elements
  long long min = a[0];
  long long max = a[0];
  long long sum = 0;
  
  for (int i = 0; i < n; i++) {
    long long current = a[i];
    if (current < min) {
      min = current;
    }
    if (current > max) {
      max = current;
    }
    sum += current;
  }
  
  std::cout << min << " " << max << " " << sum << std::endl;
  
  return 0;
}