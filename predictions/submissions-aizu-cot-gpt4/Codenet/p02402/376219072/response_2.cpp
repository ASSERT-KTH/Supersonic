#include <iostream>
#include <vector>
#include <limits>

int main() {
  int n;
  std::cin >> n;
  
  std::vector<long long> a;
  a.reserve(n);  // reserve memory upfront
  
  long long min = std::numeric_limits<long long>::max();
  long long max = std::numeric_limits<long long>::min();
  long long sum = 0LL;
  
  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    a.push_back(ii);
    
    // calculate min, max, and sum in a single loop
    if (ii < min) min = ii;
    if (ii > max) max = ii;
    sum += ii;
  }
  
  std::cout << min << " " << max << " " << sum << std::endl;
}