#include <cstdio>

int main() {
  int n;
  while (std::cin >> n && n) {
    for (int i = 0; i < 256; i++) {
      int d[256] = {};
      for (; n--; ) {
        char a, b;
        std::cin >> a >> b;
        d[a] = b - a;
      }
      for (; n--; ) {
        char a;
        std::cin >> a;
        char result = a + d[a];
        std::putchar(result);
      }
    }
  }
}