#include <stdio.h>
#include <iostream>

int main() {
  int n;
  char a, b;
  int d[256];

  while (std::cin >> n && n) {
    std::fill(d, d + 256, 0);
    for (; n--; d[a] = b - a)
      std::cin >> a >> b;
    for (std::cin >> n; n--; std::cout << char(a + d[a]))
      std::cin >> a;
    std::cout << "\n";
  }
}