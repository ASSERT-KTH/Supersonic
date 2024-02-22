#include <iostream>

int main() {
  int x, y;
  char z;
  while (true) {
    std::cin >> x >> z >> y;
    if (z == '?') {
      return 0;
    } else {
      switch (z) {
        case '+':
          std::cout << (x + y) << std::endl;
          break;
        case '-':
          std::cout << (x - y) << std::endl;
          break;
        case '/':
          std::cout << static_cast<double>(x) / y << std::endl;
          break;
        case '*':
          std::cout << (x * y) << std::endl;
          break;
      }
    }
  }
  return 0;
}