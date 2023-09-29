#include <iostream>
#define z std::cin >>
int main() {
  int n;
  for (char a, b; z n >> n; puts("")) { // optimized input
    int d[256] = {};
    for (; n--; d[a] = b - a)
      z a >> b;
    for (; n--; putchar(a + d[a])) // optimized loop
      z a;
  }
}