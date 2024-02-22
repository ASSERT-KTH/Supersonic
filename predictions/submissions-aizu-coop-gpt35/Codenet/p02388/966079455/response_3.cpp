#include <iostream>

int main() {
  int x;
  
  // Input validation
  std::cout << "Enter a positive integer: ";
  if (!(std::cin >> x) || x <= 0) {
    std::cout << "Invalid input. Please enter a positive integer.\n";
    return 1;
  }
  
  // Compute and print the cube
  std::cout << "Cube: " << (x * x * x) << "\n";
  
  return 0;
}