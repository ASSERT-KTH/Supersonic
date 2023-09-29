#include <iostream>
int main() {
  int x, y;
  std::cin >> x;
  y = x * x;
  y *= x;
  std::cout << y << "\n";
  return 0;
}