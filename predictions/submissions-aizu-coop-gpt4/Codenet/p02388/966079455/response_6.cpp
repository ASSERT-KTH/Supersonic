#include <iostream>
int main() {
  int x, y;
  std::cin >> x;
  y = x * x; // Calculate x^2
  y = y * x; // Multiply x^2 by x to get x^3
  std::cout << y << "\n";
  return 0;
}