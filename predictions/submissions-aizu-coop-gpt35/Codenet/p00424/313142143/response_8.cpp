#include <cstdio>

#define z scanf
#define puts printf
#define putchar printf

int main() {
  int n;
  for (char a, b; z("%d", &n), n; puts("")) {
    int d[256] = {};
    for (; n--; d[a] = b - a)
      z(" %c %c", &a, &b);
    for (z("%d", &n); n--; putchar("%c", a + d[a]))
      z(" %c", &a);
  }
}