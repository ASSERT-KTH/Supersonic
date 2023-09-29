#include <stdio.h>
int main() {
  int a[3];
  while (1) {
    for (int i = 0; i < 4; ++i) {
      scanf("%d", &a[i]);
    }
    if (a[0] == 0) {
      break;
    }
    for (int i = 0; i < 110000; ++i)
      putchar('(');
    printf("%d+%d+%d+%d", a[0], a[1], a[2], a[3]);
    putchar('\n');
  }
}
