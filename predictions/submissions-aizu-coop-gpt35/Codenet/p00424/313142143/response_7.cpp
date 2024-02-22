#include <iostream>

int main() {
  int n;
  while (std::cin >> n && n) {
    char a, b;
    while (n--) {
      std::cin >> a >> b;
      std::cout << static_cast<char>(b - a);
    }
    std::cout << std::endl;
  }
}