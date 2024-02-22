#include <iostream>

int main() {
  int x, y;
  std::cin >> x;
  int temp = x * x;     // Store the result of x * x in a temporary variable
  y = temp * x;         // Now, multiply the result by x, reducing the number of multiplications
  std::cout << y << "\n";
  return 0;
}