#include <iostream>

int main() {
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;

  if (n < 0) {
    std::cout << "Factorial is not defined for negative numbers." << std::endl;
    return 0;
  }

  int factorial = 1;
  for (int i = 2; i <= n; i++) {
    factorial *= i;
  }

  std::cout << "Factorial of " << n << " is " << factorial << std::endl;

  return 0;
}