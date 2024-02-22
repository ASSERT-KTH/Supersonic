#include <cstdio>

int main() {
  int n;
  while (scanf("%d", &n) == 1 && n) {
    int d[256] = {};
    while (n--) {
      char a, b;
      scanf(" %c %c", &a, &b);
      d[a] = b - a;
    }
    scanf("%d", &n);
    while (n--) {
      char a;
      scanf(" %c", &a);
      putchar(a + d[a]);
    }
    putchar('\n');
  }
}