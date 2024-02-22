#include <iostream>

int main() {
  int n;
  std::cout << "Enter a positive integer: ";
  std::cin >> n;

  // Input validation
  if (n <= 0) {
    std::cout << "Invalid input. Please enter a positive integer." << std::endl;
    return 0;
  }

  long result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;
  }

  std::cout << "Factorial of " << n << " is: " << result << std::endl;

  return 0;
}