#include <stdio.h>
int main() {
  while (1) {
    int a[4];
    for (int i = 0; i < 4; ++i) {
      scanf("%d", &a[i]);
    }
    if (a[0] == 0) {
      break;
    }
    printf("%*s%d+%d+%d+%d\n", 110001, "(", a[0], a[1], a[2], a[3]);
  }
  return 0;
}