#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);

  int64_t n; // Use a larger integer data type
  std::cin >> n;

  int64_t result = n * (n * n); // Perform a single multiplication
  std::cout << result << std::endl;

  return 0;
}