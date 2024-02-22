#include <stdio.h>
#include <string.h>

char R[99];
int i, h, b;

int main() {
  int ch;

  memset(R, 0, 99);
  i = h = b = 0;

  while ((ch = fgetc(stdin)) != EOF) {
    b += !!R[ch];
    h += !(R[ch] ^= 1 << i % 5);

    if (++i > 9) {
      printf("%d %d\n", h, b - h);
      memset(R, 0, 99);
      i = h = b = 0;
    }
  }

  return 0;
}