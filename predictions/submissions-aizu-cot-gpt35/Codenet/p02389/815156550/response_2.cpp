#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  int perimeter = a * 2 + b * 2;
  std::cout << a * b << " " << perimeter << std::endl;
}