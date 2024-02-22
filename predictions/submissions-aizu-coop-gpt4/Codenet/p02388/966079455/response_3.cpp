#include <iostream>

int main() {
  long long x, y;
  std::cin >> x;
  long long temp = x * x; // calculate x * x once and store it in a variable
  y = temp * x; // multiply the result by x to get x^3
  std::cout << y << "\n";
  return 0;
}