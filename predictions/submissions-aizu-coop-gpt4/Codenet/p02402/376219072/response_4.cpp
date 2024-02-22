#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  
  // Reserve memory ahead of time for efficiency
  std::vector<long long> a;
  a.reserve(n);
  
  long long min = LLONG_MAX, max = LLONG_MIN, sum = 0;
  for (int i = 0; i < n; i++) {
    long long num;
    std::cin >> num;
    a.push_back(num);
    
    // Update min, max, and sum in one pass
    min = std::min(min, num);
    max = std::max(max, num);
    sum += num;
  }
  
  std::cout << min << " " << max << " " << sum << std::endl;
}