#include <cstdio>

int main() {
  int n;
  for (char a, b; scanf("%d", &n), n; puts("")) {
    int d[256] = {};
    for (; n--; d[a] = b - a)
      scanf(" %c %c", &a, &b);
    for (scanf("%d", &n); n--; )
    {
      scanf(" %c", &a);
      a = a + d[a];
      putchar(a);
    }
  }
}