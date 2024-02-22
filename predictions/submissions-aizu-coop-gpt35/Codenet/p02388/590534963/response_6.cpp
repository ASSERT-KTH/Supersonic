#include <iostream>

int main() {
  int n;
  
  // Input validation
  std::cout << "Enter an integer: ";
  if (!(std::cin >> n)) {
    std::cout << "Invalid input. Exiting..." << std::endl;
    return 1;
  }
  
  // Calculate the cube using exponentiation by squaring
  int result = 1;
  int base = n;
  
  while (n > 0) {
    if (n & 1) {
      result *= base;
    }
    base *= base;
    n >>= 1;
  }
  
  std::cout << "Cube: " << result << std::endl;
  
  return 0;
}