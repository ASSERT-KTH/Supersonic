#include <iostream>

int main() {
  int x, y;
  std::cin >> x;
  int temp = x * x; // Calculate x * x once
  y = temp * x; // Multiply the result by x
  std::cout << y << "\n";
  return 0;
}