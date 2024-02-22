#include <iostream>

int main() {
  int n;
  int d[256];
  for (char a, b; std::cin >> n, n; std::cout << '\n') {
    std::fill_n(d, 256, 0); // reset array elements to 0
    for (; n--; d[static_cast<int>(a)] = b - a)
      std::cin >> a >> b;
    for (std::cin >> n; n--; putchar(a + d[static_cast<int>(a)]))
      std::cin >> a;
  }
}