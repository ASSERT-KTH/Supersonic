#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  
  std::vector<long long> a;
  a.reserve(n);  // preallocate memory
  
  long long min_val = LLONG_MAX;
  long long max_val = LLONG_MIN;
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    long long ii;
    std::cin >> ii;
    a.push_back(ii);
    
    min_val = std::min(min_val, ii);  // compare with min_val
    max_val = std::max(max_val, ii);  // compare with max_val
    sum += ii;  // add to sum
  }
  
  std::cout << min_val << " " << max_val << " " << sum << std::endl;

  return 0;
}