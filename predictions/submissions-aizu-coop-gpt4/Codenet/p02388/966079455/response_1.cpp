#include <iostream>

int main() {
  int x;
  // Check if the input is valid
  if (!(std::cin >> x)) {
    std::cerr << "Invalid input\n";
    return 1;
  }

  // Reduce the number of multiplications
  int x_square = x * x;
  int y = x_square * x;

  std::cout << y << "\n";
  return 0;
}