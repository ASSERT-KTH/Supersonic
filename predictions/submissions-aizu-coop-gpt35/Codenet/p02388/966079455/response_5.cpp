#include <iostream>

int main() {
  int x;
  
  std::cout << "Enter an integer: ";
  std::cin >> x;

  // Input validation
  if (!std::cin) {
    std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
    return 1;
  }
  
  // Calculation
  int result = x * x * x;

  // Output
  std::cout << "Cube of " << x << " is: " << result << std::endl;
  
  return 0;
}