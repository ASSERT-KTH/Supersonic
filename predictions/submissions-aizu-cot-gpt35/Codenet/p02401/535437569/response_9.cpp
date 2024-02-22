#include <iostream>

int main() {
  int x, y;
  char z;
  do {
    std::cin >> x >> z >> y;
    switch (z) {
      case '?':
        return 0;
      case '+':
        std::cout << x + y << std::endl;
        break;
      case '-':
        std::cout << x - y << std::endl;
        break;
      case '/':
        std::cout << x / y << std::endl;
        break;
      case '*':
        std::cout << x * y << std::endl;
        break;
    }
  } while (true);
  return 0;
}