#include <cstdio>

int main() {
  int n;
  for (char a; scanf("%d", &n) == 1 && n; printf("\n")) {
    for (; n--; ) {
      char b;
      scanf(" %c %c", &a, &b);
      putchar(b - a);
    }
    for (; n--; ) {
      scanf(" %c", &a);
      putchar(a);
    }
  }
}