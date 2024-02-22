#include <iostream>

int main() {
  int n;

  while(std::cin >> n && n) {
    int d[256] = {};
    char a, b;
    while (--n >= 0) {
      std::cin >> a >> b;
      d[a] = b - a;
    }
    std::cin >> n;
    while (--n >= 0) {
      std::cin >> a;
      std::cout << static_cast<char>(a + d[a]);
    }
    std::cout << "\n";
  }
}