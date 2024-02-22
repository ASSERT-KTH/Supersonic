#include <stdio.h>
#include <string.h>

char R[99];
int i = 0, h = 0, b = 0;
char c[1];

int main() {
  memset(R, 0, sizeof(R));

  while (fread(c, 1, 1, stdin)) {
    b += !!R[(int)c[0]];
    h += !(R[(int)c[0]] ^= 1 << i % 5);
    if (++i > 9) {
      printf("%d %d\n", h, b - h);
      i = h = b = 0;
    }
  }

  return 0;
}