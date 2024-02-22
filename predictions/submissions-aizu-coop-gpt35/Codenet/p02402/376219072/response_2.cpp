#include <iostream>

int main() {
  int n;
  std::cin >> n;

  long long* a = new long long[n]; // Use C-style array instead of std::vector

  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; // Read elements directly into the array
  }

  long long min_val = a[0]; // Initialize min_val with the first element
  long long max_val = a[0]; // Initialize max_val with the first element
  long long sum = a[0]; // Initialize sum with the first element

  for (int i = 1; i < n; i++) {
    if (a[i] < min_val) {
      min_val = a[i]; // Update min_val if necessary
    }
    if (a[i] > max_val) {
      max_val = a[i]; // Update max_val if necessary
    }
    sum += a[i]; // Add current element to sum
  }

  std::cout << min_val << " " << max_val << " " << sum << std::endl;

  delete[] a; // Deallocate the memory allocated for the array

  return 0;
}