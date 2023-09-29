#include <stdio.h>
int main() {
  int a[4];
  while (1) {
    int scanf_res = scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
    if (scanf_res != 4) {
      break;
    }
    for (int i = 0; i < 110000; ++i) {
      putchar('(');
    }
    printf("%d+%d+%d+%d\n", a[0], a[1], a[2], a[3]);
  }
}