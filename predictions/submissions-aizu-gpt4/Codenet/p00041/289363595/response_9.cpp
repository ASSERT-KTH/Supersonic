#include <stdio.h>

int main() {
  int a[4];
  while (scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]), a[0]) {
    printf("%*c%d+%d+%d+%d\n", 110000, '(', a[0], a[1], a[2], a[3]);
  }
  return 0;
}