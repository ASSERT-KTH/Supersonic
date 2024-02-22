#include <iostream>

int main() {
  int x, y;
  char z;

  while (true) {
    std::cin >> x >> z >> y;
    if (z == '?') {
      return 0;
    }

    int result;
    switch (z) {
      case '+':
        result = x + y;
        break;
      case '-':
        result = x - y;
        break;
      case '/':
        result = x / y;
        break;
      case '*':
        result = x * y;
        break;
    }

    std::cout << result << std::endl;
  }

  return 0;
}