#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  int n;
  for (char a, b; std::cin >> n, n; putchar('\n')) {
    int d[256] = {};
    for (; n--; d[a] = b - a)
      std::cin >> a >> b;
    for (std::cin >> n; n--; putchar(a + d[a]))
      std::cin >> a;
  }
}