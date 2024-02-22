#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  // Step 1: Allocate an array of long long values instead of using a vector
  long long* a = new long long[n];

  // Step 2: Read the input values directly into the array
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  // Step 3: Calculate the minimum, maximum, and sum values in a single loop
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

  // Step 4: Print the results
  std::cout << min_val << " " << max_val << " " << sum_val << std::endl;

  // Step 5: Deallocate the memory
  delete[] a;

  return 0;
}