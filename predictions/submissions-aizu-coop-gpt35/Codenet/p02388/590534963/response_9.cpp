#include <iostream>

int main() {
  int number;
  std::cout << "Enter a number: ";
  std::cin >> number;
  std::cout << "Cube of " << number << " is: " << number * number * number << std::endl;
  return 0;
}