#include <algorithm>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false); // Improve input handling

  std::ptrdiff_t n;
  std::cin >> n;

  int* R = new int[n]; // Dynamically allocate memory for the array

  for (std::ptrdiff_t i = 0; i < n; i++) {
    std::cin >> R[i];
  }

  int maxv = 0; // Initialize maxv to 0
  int minv = R[0]; // Initialize minv to R[0]

  for (std::ptrdiff_t i = 2; i <= n; i++) { // Start from i = 2 and include the last element
    maxv = std::max(maxv, R[i - 1] - minv); // Calculate maxv in a single loop
    minv = std::min(minv, R[i - 1]);
  }

  std::cout << maxv << std::endl;

  delete[] R; // Deallocate the dynamically allocated memory

  return 0;
}