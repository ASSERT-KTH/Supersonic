#include <stdio.h>

int main() {
  int a, b, c, d;

  while (scanf("%d", &a) == 1 && a != 0) {
    scanf("%d%d%d", &b, &c, &d);
    printf("%d+%d+%d+%d\n", a, b, c, d);
  }

  return 0;
}