#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  
  // Step 1: Preallocate the vector to avoid unnecessary reallocations
  std::vector<long long> a(n);
  
  // Step 2: Read the input directly into the vector
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  
  // Step 3: Calculate min, max, and sum in a single pass
  long long min_val = a[0];
  long long max_val = a[0];
  long long sum = a[0];
  
  for (int i = 1; i < n; i++) {
    if (a[i] < min_val) {
      min_val = a[i];
    }
    
    if (a[i] > max_val) {
      max_val = a[i];
    }
    
    sum += a[i];
  }
  
  // Step 4: Print the results
  std::cout << min_val << " " << max_val << " " << sum << std::endl;
  
  return 0;
}