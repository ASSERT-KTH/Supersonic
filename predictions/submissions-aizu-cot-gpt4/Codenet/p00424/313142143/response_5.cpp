#include <iostream>

int main() {
  char a, b;
  int n;
  while (std::cin >> n && n) {
    int d[256] = {};
    for (; n--; d[a] = b - a)
      std::cin >> a >> b;
    std::cin >> n;
    for (; n--; std::cout << static_cast<char>(a + d[a]))
      std::cin >> a;
    std::cout << std::endl;
  }
}