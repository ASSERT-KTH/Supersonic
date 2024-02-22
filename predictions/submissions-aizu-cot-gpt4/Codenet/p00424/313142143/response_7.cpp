#include <iostream>

int main() {
  int n;
  for (char a, b; std::cin >> n, n; std::cout << '\n') {
    int d[256] = {};
    for (; n--; d[a] = b - a)
      std::cin >> a >> b;
    for (std::cin >> n; n--; std::cout << char(a + d[a]))
      std::cin >> a;
  }
}