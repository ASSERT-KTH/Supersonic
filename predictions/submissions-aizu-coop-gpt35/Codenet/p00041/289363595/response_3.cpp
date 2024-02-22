#include <stdio.h>

int main() {
  int a[4];

  do {
    scanf("%d", &a[0]);

    if (a[0] == 0) {
      break;
    }

    for (int i = 1; i < 4; ++i) {
      scanf("%d", &a[i]);
    }

    for (int i = 0; i < 110000; ++i) {
      putchar('(');
    }

    printf("%d+%d+%d+%d", a[0], a[1], a[2], a[3]);
    putchar('\n');
  } while (1);

  return 0;
}