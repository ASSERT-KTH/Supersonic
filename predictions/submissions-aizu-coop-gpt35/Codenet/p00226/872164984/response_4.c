#include <stdio.h>

int main() {
  int R[99] = {0};
  int i = 0;
  int h = 0;
  int b = 0;
  int c;

  while (read(0, &c, 1) == 1) {
    i++;
    if (i > 9) {
      int count = R[c];
      b += count ? 0 : 1;
      h += count ? -1 : 1;
      R[c] = 1 - count;
    }
  }

  printf("%d %d\n", h, b - h);

  return 0;
}