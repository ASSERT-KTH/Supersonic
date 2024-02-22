#include <iostream>

int main() {
  int n;
  std::cin >> n;

  // Input validation
  if (n < 0) {
    std::cerr << "Invalid input. The number must be non-negative." << std::endl;
    return 1;
  }

  int factorial = 1;
  for (int i = 2; i <= n; i++) {
    factorial *= i;
  }

  std::cout << factorial << std::endl;
  return 0;
}