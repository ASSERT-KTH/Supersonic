#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  
  std::vector<long long> a;
  a.reserve(n);  // pre-allocate memory
  
  long long min = LLONG_MAX, max = LLONG_MIN, sum = 0;

  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    a.push_back(ii);
    
    // calculate min, max and sum
    if (ii < min) min = ii;
    if (ii > max) max = ii;
    sum += ii;
  }

  std::cout << min << " " << max << " " << sum << std::endl;

  return 0;
}