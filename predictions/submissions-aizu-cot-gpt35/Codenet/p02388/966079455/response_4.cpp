#include <iostream>

int main() {
  int x;
  std::cin >> x;
  int y = x * x;
  y *= x;
  std::cout << y << "\n";
}