#include <cstdio>

int main() {
  int n;
  while (scanf("%d", &n) == 1 && n) {
    int d[256] = {};
    for (; n--; ) {
      char a, b;
      scanf(" %c %c", &a, &b);
      d[a] = b - a;
    }
    for (; n--; ) {
      char a;
      scanf(" %c", &a);
      putchar(a + d[a]);
    }
    putchar('\n');
  }
  return 0;
}