#include <iostream>

int main() {
  int n;
  while (std::cin >> n && n) {
    int d[256] = {};
    char a;
    for (; n--; d[a] = a - getchar())
      std::cin >> a;
    for (; n--; putchar(a + d[a]))
      std::cin >> a;
    putchar('\n');
  }
}